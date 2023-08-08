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

//問題文：https://atcoder.jp/contests/abc283/tasks/abc283_b
/*
解答方針
クエリ処理の練習問題です。
はじめに、配列Aを読み込みます。
次に、Q個のクエリを読み込みます。
クエリを読み込むときは、まず先頭の数字を読み込み、それに応じて条件分岐して処理を行います。
その後の処理は難しくないため、苦もなく実装できるでしょう。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll q;
  cin >> q;
  rep(i,q){
    ll num;
    cin >> num;
    if(num == 1){
      ll k,x;
      cin >> k >> x;
      a[k-1] = x;
    }else{
      ll k;
      cin >> k;
      cout << a[k-1] << endl;
    }
  }
}