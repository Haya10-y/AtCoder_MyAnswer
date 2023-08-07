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

//問題文：https://atcoder.jp/contests/abc285/tasks/abc285_a
/*
解答方針
本コードではaとbのうち小さい方を求めていますが、制約上a < bは確定しているので気にする必要はありません。
問題文中の図を見てもらえればわかりますが、小さい方をi番目としたとき、
i番目と2i番目、i番目と2i+1番目が繋がっているということがわかっています。
そのため、b = 2aであるか、b = 2a+1であるかのどちらかであれば直接結ばれており、
そうでなければ直接結ばれていません。
*/

int main(){
  ll a,b;
  cin >> a >> b;
  ll large = max(a,b);
  ll small = min(a,b);
  if(small == large/2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}