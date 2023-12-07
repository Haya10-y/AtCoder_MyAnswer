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
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353
#define mint2 modint1000000007
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

#define endl "\n" //flushのとき外す

/*
解答方針
木はDFS・BFSによりたどることができる（一般的にはDFS）。
また、xからKを通ってyに移動する際には、この距離の合計としてはxからKまでの距離とKからyまでの距離の和となる。
そのため、Kから全頂点への距離を求めることができればあとは楽になる。
Kを始点としてDFSを行い、全頂点への距離を求めよう。
あとはクエリごとにxまでの距離、yまでの距離をO(1)で求めて足し合わせればよい。
*/

int main(){
  fast();
  ll n;
  cin >> n;
  vector<vector<ll>> g(n);
  vector<map<ll,ll>> cost(n);
  rep(i,n-1){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
    cost[a][b] = c;
    cost[b][a] = c;
  }
  ll q,k;
  cin >> q >> k;
  k--;
  vector<ll> distfromk(n,0); //kからのdist
  //dfs
  stack<ll> dfs;
  dfs.push(k); //頂点kからdfsしていく
  vector<ll> visited(n,false);
  while(!dfs.empty()){
    ll node = dfs.top();
    dfs.pop();
    visited[node] = true;
    for(auto i: g[node]){
      if(visited[i]){
        continue;
      }
      dfs.push(i);
      distfromk[i] = distfromk[node]+cost[node][i];
    }
  }
  
  rep(i,q){
    ll x,y;
    cin >> x >> y;
    x--;y--;
    cout << distfromk[x]+distfromk[y] << endl;
  }
}