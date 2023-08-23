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

//問題文：https://atcoder.jp/contests/abc272/tasks/abc272_a
/*
解答方針
A問題でもfor文が解禁されました。最初は簡単な問題です。
入力した値を答えとなる変数に足すことをN回繰り返しましょう。
Aのすべての要素を最初に配列に入れてもいいですし、ひとつずつ入力して足していっても問題ありません。
*/

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  rep(i,n){
    ll a;
    cin >> a;
    ans += a;
  }
  cout << ans << endl;
}