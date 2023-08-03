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

//問題文：https://atcoder.jp/contests/abc293/tasks/abc293_a
/*
解答方針
問題文通り、奇数番号の部分と偶数番号の部分を入れ替えましょう。
言語によって要素の入れ替え方が違うので、調べてみてください。
なお、長さは偶数であることが確定しているため、奇数番号の要素数 > 偶数番号要素数の可能性はありません。
*/

int main(){
  string s;
  cin >> s;
  ll n = sz(s);
  for(int i = 0; i <= n; i += 2){
    swap(s[i], s[i+1]);
  }
  cout << s << endl;
}