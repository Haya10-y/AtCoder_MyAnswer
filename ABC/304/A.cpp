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

//問題文：https://atcoder.jp/contests/abc304/tasks/abc304_a
/*
解答方針
A問題にしては少しむずかしめです。
年齢が最も小さい人の場所を求め、そこから1周させましょう。
場所の確認のためには、最小の年齢とその人がいる場所の変数をもって更新していけばよいです。
あとは1周ループを回しますが、配列外参照を起こさないようindexはnで割ったあまりにするとよいです。
もしくは、同じ配列を2個繋げてもよいです。これだと配列外参照を起こさずに1周させることができます。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<string> s(n);
  rep(i,n){
    cin >> s[i] >> a[i];
  }
  auto iter = min_element(all(a));
  int idx = distance(a.begin(), iter);
  //cout << idx << endl;
  rep(i,n){
    cout << s[(idx+i)%n] << endl;
  }
}