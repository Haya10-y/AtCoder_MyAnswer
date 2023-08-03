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

//問題文：https://atcoder.jp/contests/abc289/tasks/abc289_b

/*
解答方針
難しい問題です。B問題でいきなりグラフの問題を求められています。
もちろんB問題なのでグラフに関するアルゴリズムは不要なのですが、ここでは上から殴る方法をとります。
考え方としては、レ点はグラフにおける辺であることと、連結成分を最後にひっくり返せばよい、ということになります。
連結成分はUnion-Findで簡単に求められ、かつ順番をひっくり返すのも非常に簡単です。
最後に上から順番に頂点を出力していけばよいです。
難しい場合は隣り合う要素のみ繋がりうる、という性質を活かして連結成分を求めましょう。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m),p(n);
  rep(i,m){
    cin >> a[i];
  }
  rep(i,n){
    p[i] = i+1;
  }
  dsu uf(n+1);
  rep(i,m){
    uf.merge(a[i],a[i]+1);
  }
  auto g = uf.groups();
  rep(i,sz(g)){
    sort(all(g[i]));
    reverse(all(g[i]));
  }
  rep_s(i,1,sz(g)){
    rep(j,sz(g[i])){
      cout << g[i][j] << " ";
    }
  }
  cout << endl;
}