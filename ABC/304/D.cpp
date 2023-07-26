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
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353
#define mint2 modint1000000007
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc304/tasks/abc304_d
/*
解答方針
どの長方形のピースに何個いちごが乗っているか判定する必要がある。
また、ピースの縁にいちごがないことが確定しているため、境界を考える必要はない。
何行何列にいちごがあるかを判定するためには、いちごの座標をつかって二分探索すればよい。
あとはカウントをまとめ、答えを出力すればよい。
二分探索の計算量は合計でO(N(logA+logB))程度になるはず。
*/

ll distpow(ll x1, ll y1, ll x2, ll y2){
  return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
 
int main(){
  fast();
  ll w,h;
  cin >> w >> h;
  int n;
  cin >> n;
  vector<ll> p(n), q(n);
  rep(i,n){
    cin >> p[i] >> q[i];
  }
  int A,B;
  cin >> A;
  vector<int> a(A);
  
  rep(i,A){
    cin >> a[i];
  }
  a.push_back(w);
  cin >> B;
  vector<int> b(B);
  rep(i,B){
    cin >> b[i];
  }
  b.push_back(h);
  ll sectioncount = (A+1)*(B+1);
  map<pair<ll,ll>, int> mp;
  /*rep(i,sz(a)){
    cerr << a[i] << " ";
  }
  cerr << endl;
  rep(i,sz(b)){
    cerr << b[i] << " ";
  }*/
  rep(i,n){
    ll sectionx = *lower_bound(all(a), p[i]);
    ll sectiony = *lower_bound(all(b), q[i]);
    //cout << p[i] << " " << q[i] << " " << sectionx << " " << sectiony << endl;
    mp[make_pair(sectionx, sectiony)]++;
  }
  if(sz(mp) != sectioncount){
    cout << 0 << " ";
  }else{
    int mn = 1e17;
    for(auto i: mp){
      mn = min(i.second, mn);
    }
    cout << mn << " ";
  }
  int mx = -1;
  for(auto i: mp){
    mx = max(i.second, mx);
  }
  cout << mx << endl;
}