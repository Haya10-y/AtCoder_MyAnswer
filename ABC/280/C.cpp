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

//問題文：https://atcoder.jp/contests/abc280/tasks/abc280_c
/*
解答方針
Sのi文字目とTのi文字目が異なった時点でその位置を出力します。
Sを走査し終えた場合はTの最後の文字が挿入された文字になります。
挿入された文字の場所候補が複数ある場合はどこに入れてもいいので、最後に入れることを考えましょう。
*/

int main(){
  string s;
  string t;
  cin >> s;
  cin >> t;
  rep(i,sz(s)){
    if(s[i] != t[i]){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << sz(t) << endl;
}