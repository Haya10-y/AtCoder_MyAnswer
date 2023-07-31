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

//問題文：https://atcoder.jp/contests/abc302/tasks/abc302_d
/*
実装方針
贈り物の価値の差がD以下であり、その贈り物の価値の和を最大化したい。
価値の差がD以下であるということは、青木くんへの贈り物の価値をXとしたとき、
すぬけくんへの贈り物価値YはX-D <= Y <= X+Dになる、ということである。
XがわかればYの左端と右端は二分探索で簡単に求められるため、配列A,Bをソートし、
Aを全探索し、Aの要素に対応するBの要素を二分探索で求めて価値の和の最大値を記録していけばよい。
*/

int main(){
  ll n,m,d;
  cin >> n >> m >> d;
  vector<ll> a(n),b(m);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,m){
    cin >> b[i];
  }
  sort(all(a));
  sort(all(b));
  ll ans = -1;
  rep(i,n){
    ll lower = a[i]-d;
    ll upper = a[i]+d;
    ll lowb = *lower_bound(all(b),lower);
    auto highb_iter = upper_bound(all(b),upper);
    if(highb_iter != b.begin()){
      highb_iter--;
    }
    ll highb = *highb_iter;
    if(abs(highb-a[i]) <= d){
      ans = max(ans,highb+a[i]);
    }
    if(abs(lowb-a[i]) <= d){
      ans = max(ans,lowb+a[i]);
    }
  }
  cout << ans << endl;
}