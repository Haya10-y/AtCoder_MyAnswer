#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(ll i = s-1; i >= e; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
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

//問題文：https://atcoder.jp/contests/abc306/tasks/abc306_d
/*
解答方針
O(N)の動的計画法で解く。
dp[i][j]：i番目をとったときにお腹を壊しているかそうでないか (j = 0 or 1) のときのおいしさの最大値
遷移は以下のように行う。
・解毒剤入り料理 (j = 0) の場合
dp[i+1][0] = max(dp[i][1]+y[i], dp[i][0]+y[i], dp[i][0], dp[i+1][0])
毒状態から食べた場合、通常状態から食べた場合、食べなかった場合、値が更新されない場合で比較して遷移する。

・毒入り料理 (j = 1) の場合
dp[i+1][1] = max(dp[i][0]+y[i], dp[i][1], dp[i+1][1])
通常状態から食べた場合、食べなかった場合、値が更新されない場合で比較して遷移する。
なお、毒状態で毒入り料理を食べることはありえない（高橋くんが死んでしまうため）。

最終の答えはmax(dp[n][0],dp[n][1])となる。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<ll> x(n), y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  vector<vector<ll>> dp(n+1, vector<ll>(2,0));
  //dp[i][j] -> i番目をとったとき、お腹を壊しているかいないか(j)考えたときのおいしさの最大値
  
  rep(i,n){
    if(x[i] == 0){
      dp[i+1][0] = max(dp[i][1]+y[i], dp[i][0]+y[i]);
    }else{
	  dp[i+1][1] = dp[i][0]+y[i];
    }
    dp[i+1][0] = max(dp[i][0], dp[i+1][0]);
    dp[i+1][1] = max(dp[i][1], dp[i+1][1]);
  }
  /*rep(i,n){
    rep(j,2){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << max(dp[n][0], dp[n][1]) << endl;
}