#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (int bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353
#define mint2 modint1000000007
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc312/tasks/abc312_d
/*
解答方針
ありうる括弧列の個数を求める問題。
i番目まで見たとき、i-1番目までにありうる括弧列の個数だけをみてやればよく、
それより前について見る必要はない。
これをi=1まで繰り返してみると、漸化式が成り立ちそう、すなわちDPが適用できそうだ。
今回は以下のDPで考える。
dp[i][j][k] -> i番目にjをとったとき（j=0のとき左括弧、j=1のとき右括弧）に左括弧の残り個数がkであったときのパターン数
なお、このDPの計算量はO(N^2)ほどになるが、N <= 3000であるため通る。
おそらくだが、状態jは不要だろう（左括弧の残り個数だけあれば十分であるため）
あとは左括弧の残り個数が0のときに右括弧がつくパターンは絶対にありえないことに気をつけて遷移すればよい。
998244353で割ったあまりを求めることを忘れないように。C++ならmodintを使うと楽である。
*/

int main(){
  string s;
  cin >> s;
  int n = sz(s);
  vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(2, vector<mint>(n+1,0)));
  //dp[i][j][k] -> i番目にjをとったときに残り個数がkであったときのパターン数
  if(s[0] == '('){
    dp[0][0][1] = 1;
  }else if(s[0] == ')'){
    cout << 0 << endl;
    return 0;
  }else{
    dp[0][0][1] = 1;
  }
  rep_s(i,1,n){
    rep(j,n){
      if(s[i] == '(')dp[i][0][j+1] += (dp[i-1][0][j]+dp[i-1][1][j]);
      if(s[i] == ')' && j >= 1)dp[i][1][j-1] += (dp[i-1][0][j]+dp[i-1][1][j]);
      if(s[i] == '?'){
        dp[i][0][j+1] += (dp[i-1][0][j]+dp[i-1][1][j]);
        if(j>=1)dp[i][1][j-1] += (dp[i-1][0][j]+dp[i-1][1][j]);
      }
    }
  }
  cout << dp[n-1][1][0].val() << endl;
}