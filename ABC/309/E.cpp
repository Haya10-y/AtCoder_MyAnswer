#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (int bit = 0; bit < (1<<n); bit++)
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

//問題文：https://atcoder.jp/contests/abc309/tasks/abc309_e
/*
解答方針
まず、愚直解としては保険の数M回だけ木をDFS, BFSしていくというものがある。
しかしこれでは当然ながら実行時間制限に間に合わないため、別の方法を考える必要がある。
ここではDFS（あるいはBFS）を用いて、自分の下からどれだけの人間が保険対象になるか、という変数を更新していく。
DFS (BFS) にDPを組み合わせたようなアルゴリズムで探索していけば時間制限に間に合う。
実装としては上から送られてきた保険の残りの代の数が現在の保険の残りの代の数以下であればもう探索しない、とすると頂点の探索数を減らすことができる。
根は頂点1であることが確定しているため、そこから探索していこう。
木に対する探索はDFSのほうが楽であるため、通常はそちらを使おう（わたしはBFSでやってしまいました）。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> p(n,0);
  rep_s(i,1,n){
    cin >> p[i];
    p[i]--;
  }
  vector<int> x(m),y(m);
  rep(i,m){
    cin >> x[i] >> y[i];
    x[i]--;
  }
  vector<vector<int>> g(n); //木
  
  rep_s(i,1,n){
    g[i].push_back(p[i]);
    g[p[i]].push_back(i);
  }
  vector<int> dist(n,-1);
  dist[0] = 0;
  queue<int> bfs;
  vector<int> bfsorder;
  bfs.push(0);
  while(!bfs.empty()){
    int node = bfs.front();
    bfs.pop();
    bfsorder.push_back(node);
    for(auto i: g[node]){
      if(dist[i] != -1){
        continue;
      }
      dist[i] = dist[node]+1;
      bfs.push(i);
    }
  }
  vector<int> maxgen(n,-1);
  rep(i,m){
    maxgen[x[i]] = max(maxgen[x[i]],y[i]);
    //cout << y[i] << maxgen[x[i]] << endl;
  }
  rep(i,n){
    int start = bfsorder[i];
    bfs.push(start);
    while(!bfs.empty()){
      int node = bfs.front();
      bfs.pop();
      for(auto j: g[node]){
        if(maxgen[node] <= 0){
          break;
        }
        if(j == p[node]){
          continue;
        }
        if(maxgen[j] != -1 && maxgen[j] >= maxgen[node]-1){
          continue;
        }
        if(maxgen[j] == -1){
          bfs.push(j);
        }
        maxgen[j] = maxgen[node]-1;
        
      }
    }
  }
  int ans = 0;
  rep(i,n){
    //cout << maxgen[i] << " ";
    if(maxgen[i] != -1){
      ans++;
    }
  }
  cout << ans << endl;
}