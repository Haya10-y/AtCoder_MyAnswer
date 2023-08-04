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
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc291/tasks/abc291_b
/*
解答方針
配列をソートし、N番目から4N-1番目までの要素をすべて足して3Nで割ります。
数値は浮動小数点数でとり、出力するときは十分大きい桁数を出力するようにしましょう。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> x(n*5);
  rep(i,n*5){
    cin >> x[i];
  }
  double ans = 0;
  sort(all(x));
  rep_s(i,n,n*4){
    ans += x[i];
  }
  ans /= (n*3);
  cout << fixed << setprecision(15) <<ans << endl;
}