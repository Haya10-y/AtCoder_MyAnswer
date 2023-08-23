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

//問題文：https://atcoder.jp/contests/abc272/tasks/abc272_c
/*
解答方針
2要素の和として偶数を得る場合は、奇数+奇数か偶数+偶数である必要があります。
配列の要素を偶奇によって振り分けてやり、そこから一番大きいものをふたつ取り出し、偶数側と奇数側で比較します。
なお、両方とれなかった場合は-1を出力することに注意してください。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(all(a),greater());
  if(sz(a) == 2){
    if(a[0]%2 != a[1]%2){
      cout << -1 << endl;
      return 0;
    }else{
      cout << a[0]+a[1] << endl;
      return 0;
    }
  }
  
  vector<ll> odd;
  vector<ll> even;
  rep(i,n){
    if(a[i]%2==0){
      even.push_back(a[i]);
    }else{
      odd.push_back(a[i]);
    }
  }
  if(sz(even) <= 1){
    cout << odd[0]+odd[1] << endl;
    return 0;
  }
  if(sz(odd) <= 1){
    cout << even[0]+even[1] << endl;
    return 0;
  }
  cout << max(even[0]+even[1],odd[0]+odd[1]) << endl;;
}