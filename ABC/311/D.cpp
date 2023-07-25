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

//問題文：https://atcoder.jp/contests/abc311/tasks/abc311_d
/*
解答方針
グラフ上の探索アルゴリズム (BFS, DFS) で解くことができる。
通過したマスを表すpassed配列と停止したマスを表すstopped配列をもっておき、同じマスに二度と止まることがないようBFSする。
BFS中は停止するまで一方向に動き続け、その間のマスのpassedフラグをすべてtrueにする。
最終的な答えはpassedフラグがついたマスの数である。
BFSにおいては実務では本来関数をつかって実装すべきであるため、このコードには改善すべき点が多い。
計算量はO(NM)程度になる。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  //1,1からスタート
  vector<vector<bool>> stopped(n,vector<bool>(m,false));
  vector<vector<bool>> passed(n,vector<bool>(m,false));
  stopped[1][1] = true;
  passed[1][1] = true;
  queue<pair<int,int>> bfs;
  bfs.push(make_pair(1,1));
  while(!bfs.empty()){
    auto node = bfs.front();
    int x = node.second;
    int y = node.first;
    bfs.pop();
    int tmpx = x;
    int tmpy = y;
    while(true){
      tmpx++; //x+方向
      if(s[tmpy][tmpx] == '.'){
        passed[tmpy][tmpx] = true;
      }else{
        if(stopped[tmpy][tmpx-1]){
          break;
        }
        stopped[tmpy][tmpx-1] = true;
        bfs.push(make_pair(tmpy,tmpx-1));
        break;
      }
    }
    tmpx = x;
    tmpy = y;
    while(true){
      tmpx--; //x-方向
      if(s[tmpy][tmpx] == '.'){
        passed[tmpy][tmpx] = true;
      }else{
        if(stopped[tmpy][tmpx+1]){
          break;
        }
        stopped[tmpy][tmpx+1] = true;
        bfs.push(make_pair(tmpy,tmpx+1));
        break;
      }
    }
    tmpx = x;
    tmpy = y;
    while(true){
      tmpy++; //y+方向
      if(s[tmpy][tmpx] == '.'){
        passed[tmpy][tmpx] = true;
      }else{
        if(stopped[tmpy-1][tmpx]){
          break;
        }
        stopped[tmpy-1][tmpx] = true;
        bfs.push(make_pair(tmpy-1,tmpx));
        break;
      }
    }
    tmpx = x;
    tmpy = y;
    while(true){
      tmpy--; //y-方向
      if(s[tmpy][tmpx] == '.'){
        passed[tmpy][tmpx] = true;
      }else{
        if(stopped[tmpy+1][tmpx]){
          break;
        }
        stopped[tmpy+1][tmpx] = true;
        bfs.push(make_pair(tmpy+1,tmpx));
        break;
      }
    }
  }
  int ans = 0;
  rep(i,n){
    rep(j,m){
      if(passed[i][j])ans++;
    }
  }
  cout << ans << endl;
}