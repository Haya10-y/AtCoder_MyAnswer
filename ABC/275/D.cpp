#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define debug_st(x,y) cerr << x << " " << y << " "
#define debug_p(p) cerr << p.first << " " << p.second << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338


//問題文：https://atcoder.jp/contests/abc275/tasks/abc275_d
/*
解答方針
問題文通り、この問題は再帰関数を実装する問題である。
ただし、そのまま実装すると計算量が爆発してしまい、間違いなくTLEになる。
そこで使う手法がメモ化再帰である。再帰関数の答えを配列などに保存しておくことにより、
次回以降に同じ引数が与えられたときにはそれを呼び出せばよい、というものである。
これを使うことで、計算量をかなり削減することができる。
類題として、フィボナッチ数列の第1000項を求めるといったものもある。やってみよう。
*/

map<ll,ll> memo;
 
ll rec(ll k){
  if(k == 0){
    return 1;
  }
  if(memo.count(k) != 0){
    return memo[k];
  }else{
    return memo[k] = rec(k/2) + rec(k/3);
  }
}
 
int main(){
  ll n;
  cin >> n;
  ll ans = rec(n);
  cout << ans << endl;
}