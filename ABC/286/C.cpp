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

//問題文：https://atcoder.jp/contests/abc286/tasks/abc286_c
/*
解答方針
重要な性質として、Sをふたつ並べたものの中に連続する部分文字列として
すべてのローテーションパターンがあるということがあります。
また、N <= 5000より、O(N^2)が通ります。
よって、ひとつずつ始点をずらし、探索していけばよいです。
部分文字列のj文字目がn-j-1文字目と同じか判定し、そうでなければどちらかを合わせるべくB円を使います。
これを繰り返し、回文にするための費用を求めます。
すべての部分文字列における最小費用が答えになります。
*/

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  string t = "";
  t += s+s;
  //cout << t << endl;
  ll ans = INFINITY;
  rep(i,n){
    ll cost = i*a;
    rep(j,n/2){
      //cout << t[i+j] << " " << t[i+n-j-1] << endl;
      if(t[i+j] != t[n+i-j-1]){
        cost += b;
      }
    }
    ans = min(cost,ans);
  }
  cout << ans << endl;
}