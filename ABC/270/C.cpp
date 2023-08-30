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

//問題文：https://atcoder.jp/contests/abc270/tasks/abc270_c
/*
解答方針
Xを始点、Yを終点としたパスを探す問題です。
木の探索はDFSが楽です。今回は再帰を用いて実装します。
通ったノードを記録していき、端に到達してもYがなければ記録を削除していきます。
これは関数の最後に削除処理をひとつ行うようにすることで、次々と通ったノードを消していくことができます。
Yが見つかったらその時点で探索を終了します。終了処理は2箇所挿入しています。つじつまが合うよう適宜挿入しましょう。
また、このコードではYをパスの配列に入れていないため、
パス配列の中身をすべて出力したら、最後にYを出力するようにしています。
*/

int x,y;
vector<vector<int>> g;
vector<bool> visited;
vector<int> path;
bool finished = false;
void dfs(int node){
  if(finished)return;
  visited[node] = true;
  if(node == y){
    finished = true;
    return;
  }
  path.push_back(node);
  for(auto i: g[node]){
    if(visited[i])continue;
    dfs(i);
  }
  if(finished)return;
  path.pop_back();
}

int main() {
  int n,u,v;
  cin >> n >> x >> y;
  x--;y--;
  g.resize(n);
  visited.assign(n,false);
  rep(i,n-1){
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(x);
  for(auto i: path){
    cout << i+1 << " ";
  }
  cout << y+1 << endl;
}