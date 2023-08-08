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

//問題文：https://atcoder.jp/contests/abc283/tasks/abc283_a
/*
解答方針
C++のpow関数は浮動小数点数を返すため、本問題には適していません。
なのでループを使ってaをb回かけてやるのが一番簡単です。
答えの最大値は9^9 = 387420489であり、これは32bit整数でおさまるためint型でも問題ありません。
*/

int main(){
  ll a,b;
  cin >> a >> b;
  ll ans = 1;
  rep(i,b){
    ans*=a;
  }
  cout << ans << endl;
}