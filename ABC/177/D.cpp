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

//問題文：https://atcoder.jp/contests/abc177/tasks/abc177_d
/*
解答方針
友達関係には推移律が成り立ち、XとYが友達、YとZが友達ならXとZも友達になる。
この友達関係をつくるときはUnion-Findを使うことで簡単に処理することができる。

そのあと、連結成分について考える。同じグループの中に友達がいないということは、
連結成分中の全要素がバラバラになるということになる。このとき要素数がそのままグループ数になる。
また、友達関係のない人同士をくっつけても特に問題はない。そのため、別の連結成分にいる人同士はくっつけられる。
よって、人1から人Nに対して所属している連結成分のサイズを求め、その最大をとることで
最小のグループ数を求めることができる。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  dsu uf(n);
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    uf.merge(a-1,b-1);
  }
  ll mx = -1;
  rep(i,n){
    mx = max(mx,(ll)uf.size(i));
  }
  cout << mx << endl;
}