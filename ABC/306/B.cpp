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

//問題文：https://atcoder.jp/contests/abc306/tasks/abc306_b
/*
解答方針
これは教育的な問題です。静的型付け言語を使用しているかつ多倍長整数を使っていない場合、古今東西の猛者がここでWAを出すでしょう。
まず、入力で与えられうる最大値を確認しましょう。2^64-1です。
ここで、符号付き64bit整数だと最大値が2^63-1であるため、残念ながら桁あふれを起こしてしまいます。
これは、MSB (Most Significant Bit) が符号を表しているのが原因です（詳しくは調べてみてください）。
そのため、符号なし64bit整数への変換を行う必要があります。例えばC++ならunsigned long longです。
これがわかれば、あとは普通に計算してもよし、bitsetに入れてまとめて変換してもよし、です。
*/

int main(){
  int n = 64;
  bitset<64> bs(0);
  rep(i,n){
    int a;
    cin >> a;
    bs[i] = a;
  }
  cout << bs.to_ullong() << endl;
}