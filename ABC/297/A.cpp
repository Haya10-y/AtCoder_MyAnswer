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
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc297/tasks/abc297_a
/*
解答方針
for文ですべてのクリック時刻を見ていき、時刻の差がD以下であったときの時刻を出力しましょう。
ただし、当てはまるものがなければ-1を出力してください。
実装するときは、ダブルクリックが成立した時点でプログラムを終了すると楽です。
*/

int main(){
  int n,d;
  cin >> n >> d;
  vector<int> t(n);
  rep(i,n){
    cin >> t[i];
  }
  int prev = t[0];
  rep_s(i,1,n){
    if(t[i]-prev <= d){
      cout << t[i] << endl;
      return 0;
    }
    prev = t[i];
  }
  cout << -1 << endl;
}