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

//問題文：https://atcoder.jp/contests/abc282/tasks/abc282_c
/*
解答方針
ダブルクォーテーションで括られているかどうかは、フラグをもって判定すると楽です。
ダブルクォーテーションが現れるたびフラグを切り替え、フラグがオン、すなわち括られていたら","を"."に置き換えます。
なお、ダブルクォーテーションの数は偶数であるため、最後の文字が括られていないということを気にする必要はありません。
*/

int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  bool quot = false;
  rep(i,n){
    if(s[i] == '"'){
      quot = !quot;
    }
    if(s[i] == ',' && !quot){
      s[i] = '.';
    }
  }
  cout << s << endl;
}