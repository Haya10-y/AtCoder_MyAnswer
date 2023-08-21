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

//問題文：https://atcoder.jp/contests/abc274/tasks/abc274_c
/*
解答方針
アメーバiがアメーバ1の何代子であるか、という情報を持っていく。
観察記録は矛盾していないため、これをすべての番号について行い、最終的な答えを出せばよい。
vectorで処理するかmapで処理するかは自由であるが、計算量的にはvectorのほうが若干速い。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  map<ll,ll> ameba;
  ameba[1] = 0;
  rep(i,n){
    ameba[2*(i+1)] = ameba[a[i]]+1;
    ameba[2*(i+1)+1] = ameba[a[i]]+1;
  }
  rep_s(i,1,2*n+2){
    cout << ameba[i] << endl;
  }
}