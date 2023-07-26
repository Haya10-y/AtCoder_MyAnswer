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
 
//問題文：https://atcoder.jp/contests/abc310/tasks/abc310_e
/*
解答方針
愚直な解法だとO(N^2)となりTLEするため、O(N)あるいはO(NlogN)で解く必要がある。
ここではO(N)の動的計画法で解く。
要素は0か1のどちらかしかありえないため、以下のようにDPを考えた。
また、文字列sの中身はchar型であるため、実装上ではbool型に直した配列s_bをつくっている（この説明ではsとする）。
dp[i][j]：i番目における要素jの個数
dp[i][s[i]]を1、その他を0で初期化し（本コード中では遷移中に行っているが）、以下のように遷移する。
なお、"!(0&s[i+1])"の部分がNANDである。
dp[i+1][!(0&s[i+1])] += dp[i][0]
dp[i+1][!(1&s[i+1])] += dp[i][1]

最終の答えは0 <= i < nにおけるdp[i][1]の総和である。
*/

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> s_b(n);
  rep(i,n){
    s_b[i] = s[i]-'0';
  }
  vector<vector<int>> dp(n,vector<int>(2,0));
  dp[0][s_b[0]]++;
  rep(i,n-1){
    dp[i+1][s_b[i+1]]++;
    dp[i+1][!(0&s_b[i+1])] += dp[i][0];
    dp[i+1][!(1&s_b[i+1])] += dp[i][1];
  }
  /*rep(i,n){
    cout << dp[i][0] << " " << dp[i][1] << endl;
  }*/
  ll ans = 0;
  rep(i,n){
    ans += dp[i][1];
  }
  cout << ans << endl;
}