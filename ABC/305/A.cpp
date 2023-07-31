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

//問題文：https://atcoder.jp/contests/abc305/tasks/abc305_a
/*
解答方針
色々な解き方があります。
一番簡単なのは、全ての給水所について距離を測り、一番近いところを求めるものです。
これはforループを使うことで求めることができます。距離の差が更新されたら答えも更新するよう実装しましょう。
*/

int main(){
  int n;
  cin >> n;
  vector<int> v;
  rep(i,21){
    v.push_back(i*5);
  }
  int ans = 0;
  int diffmin = 1e8;
  rep(i,21){
    if(abs(v[i]-n) < diffmin){
      ans = i*5;
      diffmin = abs(v[i]-n);
    }
  }
  cout << ans << endl;
}