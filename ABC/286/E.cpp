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

//問題文：https://atcoder.jp/contests/abc286/tasks/abc286_e
/*
解答方針
まず重要なこととして、S-T間の最短距離を求めないといけないということが挙げられる。
重みなしグラフの最短経路問題はBFSで解けるが、ここに同じ距離のときのお土産の価値の総和の概念をプラスして考える。
ここにだけ注意して考えれば、実装はさほど難しくないかもしれない。
クエリはQ回与えられるため、いちいち毎回BFSしているとO(N^4)となり間に合わない。
そこで、クエリの読み込み前に前処理として全頂点から全頂点への最短距離とお土産の価値の総和を求めておく。
これはN回のBFSで行うことができ、計算量はO(N^3)に落ちる。
あとはクエリを読み込んで最大価値を呼び出せばよい。これは各クエリO(1)で終わるため、計算量はO(Q) = O(N^2)になる。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  vector<vector<pair<ll,ll>>> g(n); //max(edges)=89700
  rep(i,n){
    rep(j,n){
      if(s[i][j] == 'Y'){
        g[i].push_back(make_pair(a[j],j)); //cost, node
      }
    }
  }
  ll q;
  cin >> q;
  vector<vector<pair<ll,ll>>> distcost(n,vector<pair<ll,ll>>(n,make_pair(-1,-1)));
  rep(i,n){ //n回bfsで前処理, これでO(N^3)に抑えられる
    queue<ll> bfs;
    distcost[i][i] = make_pair(0, a[i]);
    bfs.push(i);
    while(!bfs.empty()){
      ll node = bfs.front();
      bfs.pop();
      for(auto j: g[node]){
        ll nextcost = j.first;
        ll next = j.second;
        if(distcost[i][next].first < distcost[i][node].first+1 && distcost[i][next].first != -1){
          continue; //bfsの基本だが、同距離帯を考慮する
        }
        if(distcost[i][next].second < distcost[i][node].second+nextcost){
          distcost[i][next] = make_pair(distcost[i][node].first+1, distcost[i][node].second+nextcost);
          bfs.push(next);
        }
      }
    }
  }
  rep(i,q){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    if(distcost[u][v].first != -1){
      cout << distcost[u][v].first << " " << distcost[u][v].second << endl;
    }else{
      cout << "Impossible" << endl;
    }
  }
}