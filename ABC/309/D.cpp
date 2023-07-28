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

//問題文：https://atcoder.jp/contests/abc309/tasks/abc309_d
/*
解答方針
まず前提として、このグラフは頂点1を要素としてもつ連結成分と、頂点N_1+N_2を要素としてもつ連結成分のふたつにわけられる。
この連結成分同士を繋げ、1 - N_1+N_2間の最短距離を最大化したい。
ここで考えられることとして、1からの最短距離の最大、およびN_1+N_2からの最短距離の最大はBFSで求めることができる。
つまり、1とN_1+N_2からBFSしてやればよい。
あとはそれぞれの連結成分における最短距離の最大を求め、それを足し合わせたものに追加辺分の1を加えたものが答えになる。
*/

int main(){
  int n1,n2,m;
  cin >> n1 >> n2 >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  vector<vector<int>> g(n1+n2);
  rep(i,m){
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  vector<int> distfrom0(n1,-1),distfromn(n2,-1);
  distfrom0[0] = 0;
  distfromn[n2-1] = 0;
  queue<int> bfs;
  bfs.push(0);
  while(!bfs.empty()){
    int node = bfs.front();
    bfs.pop();
    for(auto i: g[node]){
      if(distfrom0[i] != -1){
        continue;
      }
      distfrom0[i] = distfrom0[node]+1;
      bfs.push(i);
    }
  }
  bfs.push(n1+n2-1);
  while(!bfs.empty()){
    int node = bfs.front();
    bfs.pop();
    for(auto i: g[node]){
      if(distfromn[i-n1] != -1){
        continue;
      }
      distfromn[i-n1] = distfromn[node-n1]+1;
      bfs.push(i);
    }
  }
  int ans = 1;
  int tmp = 0;
  rep(i,n1){
    //cout << distfrom0[i] << " ";
    tmp = max(tmp,distfrom0[i]);
  }
  //cout << endl;
  ans += tmp;
  tmp = 0;
  rep(i,n2){
    //cout << distfromn[i] << " ";
    tmp = max(tmp,distfromn[i]);
  }
  //cout << endl;
  ans += tmp;
  cout << ans << endl;
}