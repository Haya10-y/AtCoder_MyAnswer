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
まず、数列Xは0,1からなる。これについて、1 <= i <= Nについて必ずX[A[i]] != X[B[i]]となるようなXがあるか判定したい。
これはつまり、グラフの色付けにおいて点A[i]と点B[i]の間に辺があり、お互いが違う色である必要があるということになる。
最終的には二部グラフ判定に帰着させることができる。A[i]とB[i]間に辺を張り、これらが違う色になるようにグラフに色を着色していく。
最後まで色が塗れたらYes、途中で矛盾が生じたらNoを出力すればよい。
*/

int main(){
  fast();
  int n,m;
  cin >> n >> m;
  vector<set<int>> g(n); //多重辺を考えない
  int start = -1;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i];
  }
  rep(i,m){
    cin >> b[i];
  }
  rep(i,m){
    a[i]--; b[i]--;
    if(a[i] == b[i]){
      cout << "No" << endl;
      return 0;
    }
    if(start == -1)start = a[i];
    g[a[i]].insert(b[i]);
    g[b[i]].insert(a[i]);
  }
  vector<int> color(n,-1);
  //二部グラフ判定
  rep(i,n){
    queue<int> bfs;
    bfs.push(i);
    if(color[i] == -1){
      color[i] = 0;
    }else{
      continue;
    }
    //cout << "bfs" << endl;
    while(!bfs.empty()){
      int node = bfs.front();
      bfs.pop();
      for(auto i: g[node]){
        if(color[i] == -1){
          color[i] = !(color[node]);
          bfs.push(i);
        }else if(color[i] == color[node]){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}