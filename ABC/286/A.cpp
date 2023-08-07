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

//問題文：https://atcoder.jp/contests/abc286/tasks/abc286_a
/*
解答方針
q-p回、p+iとr+iをスワップしましょう。
制約上、p,q,r,sの位置関係を気にする必要はありません。
*/

int main(){
  ll n,p,q,r,s;
  cin >> n >> p >> q >> r >> s;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  p--;q--;r--;s--;
  rep(i,q-p+1){
    //cout << r+i << endl;
    swap(a[p+i],a[r+i]);
  }
  
  
  rep(i,n){
    cout << a[i] << " ";
  }
  cout << endl;
}