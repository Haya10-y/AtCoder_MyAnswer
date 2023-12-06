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

/*
解答方針
目と目が合ったらポケモンバトル。バトルを回避しつつ最短距離で目的地まで行きたい。
まずはそれぞれの人について視線の先を通れないようにしよう。
この部分は三重ループで書くが、各マスについてたかだか上下左右の4回しか判定されないのでO(HW)で終わる。
あとはBFSをすることで最短距離を求められる。目的地に届かなかった場合は-1を出力すること。
*/

int main(){
  fast();
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  vector<vector<bool>> ispassable(h,vector<bool>(w,true));
  pair<int,int> start,goal;
  //まず愚直から
  rep(i,h){
    rep(j,w){
      int len = 1;
      if(a[i][j] == '>'){
        ispassable[i][j] = false;
        while(j+len < w && a[i][j+len] == '.'){
          ispassable[i][j+len] = false;
          len++;
        }
      }else if(a[i][j] == '<'){
        ispassable[i][j] = false;
        while(j-len >= 0 && a[i][j-len] == '.'){
          ispassable[i][j-len] = false;
          len++;
        }
      }else if(a[i][j] == 'v'){
        ispassable[i][j] = false;
        while(i+len < h && a[i+len][j] == '.'){
          ispassable[i+len][j] = false;
          len++;
        }
      }else if(a[i][j] == '^'){
        ispassable[i][j] = false;
        while(i-len >= 0 && a[i-len][j] == '.'){
          ispassable[i-len][j] = false;
          len++;
        }
      }else if(a[i][j] == '#'){
        ispassable[i][j] = false;
      }else if(a[i][j] == 'S'){
        start = make_pair(i,j);
      }else if(a[i][j] == 'G'){
        goal = make_pair(i,j);
      }
    }
  }
  vector<vector<int>> dist(h,vector<int>(w,-1));
  queue<pair<int,int>> bfs;
  bfs.push(start);
  dist[start.first][start.second] = 0;
  while(!bfs.empty()){
    auto node = bfs.front();
    bfs.pop();
    int y = node.first;
    int x = node.second;
    
    //左
    if(x-1 >= 0 && ispassable[y][x-1] && dist[y][x-1] == -1){
      bfs.push(make_pair(y,x-1));
      dist[y][x-1] = dist[y][x]+1;
    }
    //右
    if(x+1 < h && ispassable[y][x+1] && dist[y][x+1] == -1){
      bfs.push(make_pair(y,x+1));
      dist[y][x+1] = dist[y][x]+1;
    }
    //上
    if(y-1 >= 0 && ispassable[y-1][x] && dist[y-1][x] == -1){
      bfs.push(make_pair(y-1,x));
      dist[y-1][x] = dist[y][x]+1;
    }
    //下
    if(y+1 < h && ispassable[y+1][x] && dist[y+1][x] == -1){
      bfs.push(make_pair(y+1,x));
      dist[y+1][x] = dist[y][x]+1;
    }
  }
  cout << dist[goal.first][goal.second] << endl;
}