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

/*
解答方針
時間計算の問題。
hourはNを3600で割り、minuteはNを3600で割ったあまりを60で割り、secondはNを60で割ったあまりである。
*/

int main(){
  ll n;
  cin >> n;
  ll h = n/3600;
  ll m = (n%3600)/60;
  ll s = n%60;
  if(h <= 9){
    cout << 0;
  }
  cout << h << ":";
  if(m <= 9){
    cout << 0;
  }
  cout << m << ":";
  if(s <= 9){
    cout << 0;
  }
  cout << s << endl;
}