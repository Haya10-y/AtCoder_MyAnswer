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
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc280/tasks/abc280_b
/*
解答方針
累積和の逆を考えればよいです。
A_2はS_2 - S_1であり、A_3はS_3 - S_2です。
これを一般化すると、A_i = S_i - S_(i-1)になります。
ループで処理してやりましょう。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> s(n);
  rep(i,n){
    cin >> s[i];
  }
  vector<ll> a(n);
  a[0] = s[0];
  rep_s(i,1,n){
    a[i] = s[i]-s[i-1];
  }
  rep(i,n){
    cout << a[i] << " ";
  }
  cout << endl;
}