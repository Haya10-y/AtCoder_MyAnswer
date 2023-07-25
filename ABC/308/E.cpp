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

//問題文：https://atcoder.jp/contests/abc308/tasks/abc308_e
/*
解答方針
部分文字列とMEX。部分文字列というとDPが思いつくだろう。
dp[i][j][k]：i番目にj (none, M, E, X) までとったときで、集合の状態がkであるときの場合の数
kは3ビットの集合として表すことができるため、この問題をbitDPとして解くことができる。
遷移は以下のようになる。
・i番目をとらない場合
dp[i+1][j][k] += dp[i][j][k]
・i番目をとる場合
dp[i+1][j+1][k|(1<<a[i])] += dp[i][j][k]
最終的な答えは、0 <= i <= nにおけるdp[n][3][i]に対して部分集合iに対応するmexの値をかけたものの総和である。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  string s;
  cin >> s;
  ll ans = 0;
  vector<int> mexval = {0,1,0,2,0,1,0,3};
  vector<char> mex = {'M', 'E', 'X','.'};
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(4, vector<ll>(8,-1)));
  //dp[i][j][k] -> i番目にjまでとったときで状態kのときの場合の数
  dp[0][0][0] = 1;
  rep(i,n){
    rep(j,4){
      rep(k,8){
        if(dp[i][j][k] == -1) continue; //そもそもこの状態がありえないとき
        if(dp[i+1][j][k] == -1)dp[i+1][j][k]++;
        dp[i+1][j][k] += dp[i][j][k]; //とらないときも考える
        if(s[i] != mex[j]){
          continue; //次のやつでなければスルー
        }
        ll nextk = k | (1<<a[i]);
        if(dp[i+1][j+1][nextk] == -1)dp[i+1][j+1][nextk]++;
        dp[i+1][j+1][nextk]+=dp[i][j][k];
      }
    }
  }
  rep(j,8){
    if(dp[n][3][j]==-1)continue;
    ans += mexval[j]*dp[n][3][j];
  }
  cout << ans << endl;
}