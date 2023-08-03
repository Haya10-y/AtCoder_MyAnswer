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

//問題文：
/*
解答方針
人iが呼ばれたかどうかをフラグで管理します。
1からNに対して、以下のことを行います。
人iが呼ばれていなければ、人A_iを呼びます。つまりA_iのフラグを立てます。

これを行ったあと、フラグが立っていない人の人数を求めて出力し、
そのあとにフラグが立っていない人の番号を出力していけばよいです。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<bool> x(n,false);
  rep(i,n){
    if(!x[i]){
      x[a[i]-1] = true;
    }
  }
  ll k = 0;
  rep(i,n){
    if(!x[i]){
      k++;
    }
  }
  cout << k << endl;
  rep(i,n){
    if(!x[i]){
      cout << i+1 << " ";
    }
  }
  cout << endl;
}