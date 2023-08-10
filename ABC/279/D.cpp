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
#define mod1 998244353

//問題文：https://atcoder.jp/contests/abc279/tasks/abc279_d
/*
解答方針
地面に到達する時刻Tは、操作回数をNとしたときT = BN + A*sqrt(1+N)である。
この関数は下に凸な関数であり、そのためどこかに極小値（最小値）が存在する。
この極小値は微分を用いることで求めることができるため、ここを求めたい。
ここで、上の式をNで微分するとN = (A^(2/3) / (2B)^(2/3))-1となる。
A/2Bの立方根をとって2乗し、1を引いてやればNの解析解が求まる。
ただし、解析解はほとんどの場合で小数であるため、整数解を求めるために周囲の値をとったうえでTの最小値を求め、
それに対応するNを出力すればよい。
微分の手計算は難しいので、Wolfram Alphaなどに任せよう。Tをy、Nをxとおいてやると
いい感じに計算してくれる。
*/

int main(){
  ll a,b;
  cin >> a >> b;
  ld g = 1;
  ld t = 0;
  ld cb = cbrt((ld)a/((ld)b*2));
  ld lcmin = cb*cb-1;
  //cout << lcmin << endl;
  ll left = max(0ll,(ll)floor(lcmin)-100);
  ll right = (ll)(floor(lcmin))+100;
  ld val = INFINITY;
  ll n;
  rep_s(i,left,right){
    ld tmp = (ld)i*(ld)b+(ld)a/sqrtl((ld)(i+1));
    if(tmp < val){
      val = tmp;
      n = i;
    }
  }
  ld ans = (ld)(n*b)+(ld)a/sqrtl((ld)(n+1));
  cout << setprecision(30) << ans << endl;
}