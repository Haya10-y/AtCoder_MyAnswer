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

//問題文：https://atcoder.jp/contests/abc288/tasks/abc288_b
/*
解答方針
上位K人の名前のみを読み込み、それらを昇順ソートして出力します。辞書順最小とはつまり昇順ソートの順番です。
上位K人以外は読み込む必要がありません。むしろ読み込まないほうが楽です。
*/

int main(){
  ll n,k;
  cin >> n >> k;
  vector<string> s(k);
  rep(i,k){
    cin >> s[i];
  }
  sort(all(s));
  rep(i,k){
    cout << s[i] << endl;
  }
}