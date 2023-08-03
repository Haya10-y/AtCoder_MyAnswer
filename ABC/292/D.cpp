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

//問題文：https://atcoder.jp/contests/abc292/tasks/abc292_d
/*
解答方針
連結成分を求めるためには、Union-Findを用いればよい。
あとは各連結成分ごとに辺の数を求めればよい。ここで、連結成分の頂点から伸びるすべての辺の先は同じ連結成分内にあることに注目する。
そのため各頂点から有向辺が伸びていると考え、この有向辺の数を求めたあとに2で割れば辺の数が求まる。
連結成分の頂点数は簡単に求まるため、あとはこれを比較すればよい。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  dsu uf(n);
  //cout << "safe" << endl;
  rep(i,m){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
    //cout << "safe" << endl;
    uf.merge(u,v);
  }
  //cout << "safe" << endl;
  auto group = uf.groups();
  //cout << "safe" << endl;
  rep(i,sz(group)){
    ll nodes = sz(group[i]);
    ll edges = 0;
    rep(j,sz(group[i])){
      //cout << group[i][j] << endl;
      edges += sz(g[group[i][j]]);
    }
    edges /= 2;
    //cout << nodes << " " << edges << endl;
    if(nodes != edges){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}