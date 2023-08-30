#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define all(a) a.begin(),a.end()
#define sz(v) ((int)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353;

//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc267/tasks/abc267_d
/*
解答方針
M個の部分和の最大値を求めるような問題。
N,M <= 2000であるため、O(NM)のDPが使えそうだ。
dp[i][j] -> i番目までにj個とったときのmax((j+1)*a[i]) として計算してみよう。
i番目をとるかとらないかで遷移し、これをすべてのjについて行おう。
*/

int main(){
  fast();
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1e17)); //最小値は -2e15 より大きい？十分小さい数をとる
  //dp[i][j] -> i番目までにj個とったときのmax((j+1)*a[i]).
  dp[0][0] = 0;
  rep(i,n){
    rep(j,m+1){
      dp[i+1][j] = max(dp[i+1][j],dp[i][j]); //a[i]をとらない場合
      if(j+1 <= m){
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (j+1)*a[i]); //a[i]をとる場合
      }
    }
  }
  cout << dp[n][m] << endl;
}