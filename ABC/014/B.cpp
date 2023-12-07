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

/*
解答方針
この問題では整数Xはbit列として表す。
実際は0 <= i < Nに対してx & 1<<iでbitが立っているか調べればよいが、難しい場合はbitsetを使うことで簡単に解くことができる。
bitが立っていればその商品の価格を足していく。
*/

int main(){
  ll n,x;
  cin >> n >> x;
  bitset<20> bit(x);
  //cout << bit << endl;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll ans = 0;
  rep(i,n){
    if(bit[i]){
      ans += a[i];
    }
  }
  cout << ans << endl;
}