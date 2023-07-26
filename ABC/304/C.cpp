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

//問題文：https://atcoder.jp/contests/abc304/tasks/abc304_c
/*
解答方針
まず、N <= 2000であることからO(N^2)が通る。
人iと人jとのユークリッド距離がD以下であるときに辺を張る。これを合計N(N-1)/2回行う。
あとは人1と連結しているかみればよい。これはグラフの探索アルゴリズム (DFS, BFS) か、Union-Findで判定できる。
*/


ll distpow(ll x1, ll y1, ll x2, ll y2){
  return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
 
int main(){
  fast();
  int n,d;
  cin >> n >> d;
  ll dpow = d*d;
  vector<int> x(n), y(n);
  rep(i,n){
    cin >> x[i] >> y[i];
  }
  dsu uf(n);
  rep(i,n){
    rep(j,n){
      if(distpow(x[i],y[i],x[j],y[j]) <= dpow){
        uf.merge(i,j);
      }
    }
    
  }
  rep(i,n){
    if(uf.same(0, i)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}