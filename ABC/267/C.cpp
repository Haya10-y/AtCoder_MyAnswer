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

//問題文：https://atcoder.jp/contests/abc267/tasks/abc267_c
/*
解答方針
左から順番に見ていきたいが、愚直にやろうとするとO(N^2)程度かかってしまいTLEしてしまう。
ここで、ひとつ右にずらしたときの差分について考える。
たとえば1*A_1+2*A_2+3*A_3+4*A_4と、1*A_2+2*A_3+3*A_4+4*A_5の差分について考える。
このとき、差は4*A_5-A_4-A_3-A_2-A_1となる。
ここで、式変形すると4*A_5-(A_1+A_2+A_3+A_4)となり、A_1+A_2+A_3+A_4は累積和をとればO(1)で求められる。
これを繰り返し行い、最大値を求めればよい。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> sum(n+1,0);
  vector<ll> sum_c(n+1,0);
  rep(i,n){
    cin >> a[i];
    sum[i+1] = sum[i]+a[i];
  }
  /*if(n == m){
    ll ans = 0;
    rep(i,n){
      ans += (i+1)*a[i];
    }
    cout << ans << endl;
    return 0;
  }*/
  rep(i,m){
    sum_c[0] += a[i];
  }
  rep_s(i,1,n-m+1){
    sum_c[i] = sum_c[i-1]+a[i+m-1]-a[i-1];
  }
  
  ll now = 0;
  rep(i,m){
    now += (i+1)*a[i];
  }
  ll mx = now;
  //cout << mx << endl;
  rep(i,n-m){
    now = now - (sum_c[i]) + m*a[i+m];
    //cout << now << endl;
    mx = max(now, mx);
  }
  cout << mx << endl;
}