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

//問題文：https://atcoder.jp/contests/abc284/tasks/abc284_c
/*
解答方針
グラフの連結成分はグラフ上の探索アルゴリズム (DFS, BFS) でも求められますが、今回はもっと簡単な方法を提示します。
AC LibraryにはDSU (Disjoint Set Union) があり、これはいわゆるUnion-Findです。
https://atcoder.github.io/ac-library/production/document_ja/dsu.html
これを用いることで、連結成分の個数を楽に求めることができます。
茶色以降でも頻出なので、覚えておきましょう。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  dsu uf(n);
  rep(i,m){
    ll u,v;
    cin >> u >> v;
    u--; v--;
    uf.merge(u,v);
  }
  auto g = uf.groups();
  cout << sz(g) << endl;
}