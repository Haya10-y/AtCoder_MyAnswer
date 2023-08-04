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

//問題文：https://atcoder.jp/contests/abc288/tasks/abc288_c
/*
解答方針
グラフの閉路検出はUnion-Findで簡単に行うことができます。
繋ぐ予定の辺がすでに連結であったときに閉路ができてしまうため、その辺を繋がずに削除します。
これを繰り返し、削除する辺の数をカウントして最後に出力します。
C++だとAC LibraryにUnion-Findがあるので、それを使うと楽です。他の言語の場合は調べてみてください。
https://atcoder.github.io/ac-library/production/document_ja/dsu.html
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  vector<vector<ll>> t(n);
  dsu uf(n);
  ll cnt = 0;
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    if(!uf.same(a,b)){
      uf.merge(a,b);
    }else{
      cnt++;
    }
  }
  cout <<cnt << endl;
}