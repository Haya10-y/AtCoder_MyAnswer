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
 
//問題文：https://atcoder.jp/contests/abc284/tasks/abc284_e
/*
解答方針（解説AC）
単純パスの個数とは、すなわちDFSの回数である。
visitedフラグを適切に管理することで、すべてのパスを数え上げることができる。
ただし、10^6回を超えたら強制終了することに気をつける。
次数は10以下なので、強制終了は十分間に合う。
*/

vector<vector<int>> g;
vector<int> visited;
int ans = 0;
void dfs(int node){
  if(ans >= 1e6){
    return;
  }
  ans++;
  visited[node] = true;
  for(int i: g[node]){
    if(!visited[i])dfs(i);
  }
  visited[node] = false;
}
 
int main(){
  fast();
  int n,m;
  cin >> n >> m;
  g.resize(n);
  visited.resize(n);
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  dfs(0);
  cout << ans << endl;
}