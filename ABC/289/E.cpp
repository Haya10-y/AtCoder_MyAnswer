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

//問題文：https://atcoder.jp/contests/abc289/tasks/abc289_e
/*
解答方針
移動回数を聞かれているため、おそらく最短経路問題と同じように解きそう。
また、状態数が少ないため、高橋くんおよび青木くんの位置を独立にして解かなくてもよさそうだ。
そのため、dist[t][a]を高橋くんがtに、青木くんがaにいたときの最小行動回数とし、
高橋くんと青木くんの位置をそれぞれもったBFSを行えばO(N^2+M^2)程度で終わらせることができる。
行動回数について、未訪問の場合は-1、状態がありえない場合はINFINITYとして処理している。
最終的な答えはdist[n][1] (1-indexed) である。
*/ 
 
int main(){
  ll t;
  cin >> t;
  rep(i,t){
    ll n,m;
    cin >> n >> m;
    vector<ll> C(n);
    //mincnt = 10000;
    rep(i,n){
      cin >> C[i];
    }
    vector<vector<ll>> g(n);
    //seen.assign(n,false);
    rep(i,m){
      ll u,v;
      cin >> u >> v;
      u--;v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    dist[0][n-1] = 0;
    //cout << "before bfs" << endl;
    queue<pair<ll,ll>> bfs;
    bfs.push(make_pair(0,n-1));
    while(!bfs.empty()){
      auto node = bfs.front();
      ll node_t = node.first;
      ll node_a = node.second;
      bfs.pop();
      //cout << node_t << " " << node_a << endl;
      for(auto vt: g[node_t]){
        for(auto va: g[node_a]){
          //cout << vt << " " << va << endl;
          if(dist[vt][va] != -1){
            continue;
          }
          if(C[vt] != C[va]){
            
            bfs.push(make_pair(vt,va));
            dist[vt][va] = dist[node_t][node_a]+1;
          }else{
            dist[vt][va] = INFINITY;
          }
        }
      }
    }
    /*rep(i,n){
      rep(j,n){
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;*/
    if(dist[n-1][0] == -1 || dist[n-1][0] >= 1e17){
      cout << -1 << endl;
    }else{
      cout << dist[n-1][0] << endl;
    }
  }
  
}