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

//問題文：https://atcoder.jp/contests/abc276/tasks/abc276_e
/*
解答方針
この問題文の意図は、「Sを含む長さ4以上の閉路があるか」ということである。
Sを除き、2度通る点はないため単純なグラフアルゴリズムでも解くことができそうだ。
もちろん幅優先探索やUnion-Findでも解けるが、今回はSに到達したときの深さが
いくつであるか、ということを考えたいため深さ優先探索で解いた。
また、現在の経路の長さをもっておくとよいということもあるため、再帰を用いて関数の引数として現在の経路の長さをもつことにした。
*/

vector<vector<int>> g;
int maxlength = 0;
int start;
vector<bool> visited;
void dfs(int node, int length){
  if(maxlength >= 4){
    return;
  }
  visited[node] = true;
  
  for(auto i: g[node]){
    if(i == start){
      maxlength = max(length, maxlength);
    }
    if(!visited[i]){
      dfs(i,length+1);
    }
  }
}
 
int main(){
  //問題の意図 -> Sを含む閉路を検出し、そのサイズが4以上であればYes.
  int h,w;
  cin >> h >> w;
  vector<vector<char>> c(h,vector<char>(w));
  
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
      if(c[i][j] == 'S'){
        start = i*w+j;
      }
    }
  }
  g.resize(h*w); //2次元構造を1次元におきかえる（やりづらいので）
  visited.assign(h*w, false);
  rep(i,h){
    rep(j,w){
      //すべての頂点に対してやるので逆に辺を張る必要はない
      if(i-1 >= 0 && c[i][j] != '#' && c[i-1][j] != '#'){
        g[i*w+j].push_back((i-1)*w+j);
      }
      if(i+1 < h && c[i][j] != '#' && c[i+1][j] != '#'){
        g[i*w+j].push_back((i+1)*w+j);
      }
      if(j-1 >= 0 && c[i][j] != '#' && c[i][j-1] != '#'){
        g[i*w+j].push_back(i*w+j-1);
      }
      if(j+1 < w && c[i][j] != '#' && c[i][j+1] != '#'){
        g[i*w+j].push_back(i*w+j+1);
      }
    }
  }
  dfs(start,1);
  cerr << maxlength << endl;
  if(maxlength >= 4){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}