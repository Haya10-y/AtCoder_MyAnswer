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
 
//問題文：https://atcoder.jp/contests/abc308/tasks/abc308_d
/*
解答方針
(1,1)から(H,W)に移動できるかどうかは、グラフ上の探索アルゴリズム(DFS, BFS)で判定することができる。
今回はそれに条件がついている(s,n,u,k,e,s,n,u,k,e,...)ため、ひとつ追加で状態をもったDFS,BFSを行えばよい。
移動先の候補が条件を満たしているか考え、満たしていたら移動先を追加していけばよい。
計算量はO(HW)である。
*/


bool comp(pair<ld,int> a, pair<ld,int> b){
  return a.first > b.first;
}

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h){
    cin >> s[i];
  }
  vector<char> snuke = {'s', 'n', 'u', 'k', 'e'};
  vector<vector<bool>> visited(h,vector<bool>(w,false));
  vector<int> tmp(3,0);//0をy,1をx,2をnext
  queue<vector<int>> bfs;
  bfs.push(tmp);
  int next = 0;
  while(!bfs.empty()){
    auto node = bfs.front();
    int x = node[1];
    int y = node[0];
    int next = (node[2]+1)%5;
    node[2] = next;
    bfs.pop();
    visited[y][x] = true;
    if(y-1 >= 0 && !visited[y-1][x] && s[y-1][x] == snuke[next]){
      node[1] = x;
      node[0] = y-1;
      visited[y-1][x] = true;
      bfs.push(node);
    }
    if(y+1 < h && !visited[y+1][x] && s[y+1][x] == snuke[next]){
      node[1] = x;
      node[0] = y+1;
      visited[y+1][x] = true;
      bfs.push(node);
    }
    if(x-1 >= 0 && !visited[y][x-1] && s[y][x-1] == snuke[next]){
      node[1] = x-1;
      node[0] = y;
      visited[y][x-1] = true;
      bfs.push(node);
    }
    if(x+1 < w && !visited[y][x+1] && s[y][x+1] == snuke[next]){
      node[1] = x+1;
      node[0] = y;
      visited[y][x+1] = true;
      bfs.push(node);
    }
  }
  /*rep(i,h){
    rep(j,w){
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }*/
  if(visited[h-1][w-1]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}