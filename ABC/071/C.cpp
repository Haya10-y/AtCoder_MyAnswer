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
長方形をつくれるとき、それすなわち長さの同じ2本の棒が2セットあるということになる。
棒の長さに対するカウントをmapなどでとり、一番大きいものをとって面積を計算すればよい。
*/

int main(){
  ll n;
  cin >> n;
  map<ll,ll> mp;
  rep(i,n){
    ll a;
    cin >> a;
    mp[a]++;
  }
  vector<pair<ll,ll>> v(all(mp));
  ll width = 0;
  ll height = 0;
  rep_r(i,sz(v)){
    if(width == 0 && height == 0 && v[i].second >= 4){
      width = v[i].first;
      height = v[i].first;
      break;
    }
    if(width == 0){
      if(v[i].second >= 2){
        width = v[i].first;
      }
    }else{
      if(v[i].second >= 2){
        height = v[i].first;
      }
    }
    if(width != 0 && height != 0){
      break;
    }
  }
  cout << width * height << endl;
}