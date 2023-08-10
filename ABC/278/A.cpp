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
#include <atcoder/all>
using namespace atcoder;

//問題文：https://atcoder.jp/contests/abc278/tasks/abc278_a
/*
解答方針
配列をK回左シフトする問題です。
K回左シフトするということは、左からK番目から出力し始めるということです。
もとの配列の最後になるまで出力してから、残り回数分0を出力しましょう。
なお、残り回数はNとKのうち小さい方です。
*/

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  rep_s(i,k,n){
    cout << a[i] << " ";
  }
  rep(i,min(n,k)){
    cout << 0 << " ";
  }
  cout << endl;
}