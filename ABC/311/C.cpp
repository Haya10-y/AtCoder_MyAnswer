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

//問題文：https://atcoder.jp/contests/abc311/tasks/abc311_c
/*
解答方針
この問題の制約上DFSやBFSでN回たどれば必ずサイクルに当たるのだが、今回はSCC（強連結成分分解）を使った。
SCCにより、有向グラフの強連結成分（本制約ではサイクルになる）を検出することができる。
AtCoder LibraryにSCCができるライブラリがあるので、それを使うと楽。→https://atcoder.github.io/ac-library/production/document_ja/scc.html
あとは強連結成分のうち頂点数が2以上であるものを選び、その1点から順番にたどった点を出力すればよい。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  /*vector<vector<int>> g(n);
  rep(i,n){
    g[i].push_back(a[i]-1);
  }*/
  scc_graph graph(n);
  rep(i,n){
    graph.add_edge(i,a[i]-1);
  }
  
  vector<vector<int>> sorted = graph.scc();
  int idx = 0;
  rep(i,sz(sorted)){
    if(sorted[i].size() >= 2){
      idx = i;
      break;
    }
  }
  cout << sz(sorted[idx]) << endl;
  sort(all(sorted[idx]));
  int ans = sorted[idx][0];
  cout << ans+1 << " ";
  
  while(true){
    ans = a[ans]-1;
    if(ans == sorted[idx][0])break;
    cout << ans+1 << " ";
  }
  cout << endl;
}