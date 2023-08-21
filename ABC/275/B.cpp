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

//問題文：https://atcoder.jp/contests/abc275/tasks/abc275_b
/*
解答方針
ABC >= DEFであり、ABC-DEF < 0になることはありません。
すべての数字は10^18を超えることがあり、そのまま計算するとオーバーフローしてしまいます。
ここで、剰余の特性を活かします。
(a*b) % m = ((a%m)*(b%m)) % mという特性を活かすことで、
オーバーフローさせずにこの問題を解くことができます。
より簡易的な解法として、AC Libraryにあるmodint構造体を使う方法もあります。
https://atcoder.github.io/ac-library/production/document_ja/modint.html
modの概念はDP問題などで非常に重要であるため、覚えておきましょう。
*/

int main(){
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  ll mod = 998244353;
  ll amod = a%mod;
  ll bmod = b%mod;
  ll cmod = c%mod;
  ll dmod = d%mod;
  ll emod = e%mod;
  ll fmod = f%mod;
  ll abmod = (amod*bmod)%mod;
  ll abcmod = (abmod*cmod)%mod;
  ll demod = (dmod*emod)%mod;
  ll defmod = (demod*fmod)%mod;
  ll ans = (abcmod-defmod+mod)%mod;
  cout << ans << endl;
}