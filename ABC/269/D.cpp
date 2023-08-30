#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
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

//問題文：https://atcoder.jp/contests/abc269/tasks/abc269_d
/*
解答方針
六角形グリッドについて、連結成分の個数を求めるものである。
マスに番号を振っておき、連結リストをつくろう。連結かどうかの条件は問題文中にある。
また、本コード中ではマスの番号は入力の順番に等しい。Nが小さいため、O(N^2)で連結の判定ができる。
連結成分の個数はDFS・BFS・Union-Findで求められるため、これで問題に正解することができる。本コード中ではDFSを使っている。
なお、連結成分を求めるうえで最も簡単なのがUnion-Findである。AC Libraryに入っているため、あわせて覚えておこう。
https://atcoder.github.io/ac-library/production/document_ja/dsu.html
*/

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
// 深さ優先探索
vector<bool> seen;  // 探索したか記録
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto e : G[v]) {
        if (!seen[e.to]) {  // 訪問済みでなければ探索
            dfs(G, e.to);
        }
    }
}

int main() {
  int n;
  cin >> n;
  Graph G(n);  // グラフを表現する隣接リスト
  vector<int> x(n);
  vector<int> y(n);
  rep(i,n){
     cin >> x[i] >> y[i];
  }
  int dx[6] = {-1,-1,0,0,1,1};
  int dy[6] = {-1,0,-1,1,0,1};
  // 隣接リストを作成
  rep(i,n) {
    rep(j,n){
      if(i == j){
        continue;
      }
      rep(k,6){
        if(x[i] == x[j] + dx[k] && y[i] == y[j] + dy[k]){
          //cerr << i << " " << j << endl;
          G[i].push_back({j});
        }
      }
    }
  }

  seen.assign(n, false);  // 初期化
  int cnt = 0; 
  for (int i = 0; i < n; i++) {
    if (!seen[i]) {
      dfs(G, i);
      cnt++; // dfsした回数をカウント
    }
  }
  cout << cnt << endl;
  return 0;
}