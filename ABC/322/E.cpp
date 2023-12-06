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
DPで解くことは想像できるが、具体的にどう解くのか考える必要がある。
ここで、同じ開発案を2回以上実行することはなく、またパラメータの個数・上限はともに5である。
5個のパラメータが0~5まであると考えると、このパラメータ群の種類数はたかだか6^5=7776個になる。
そのうえ、開発案はたかだか100個までであるため、すべての種類のパラメータ群に対して開発案を試しても十分間に合う。
DPテーブルとしてmapを使い、キーをパラメータ群とする。
ありうるすべてのパラメータ群に対し、開発案を実行してコストの最小値を更新していく。
最終的にすべてのパラメータがPになったものがあればそのコストの最小値を出し、それがなければ-1を出す。
*/

int main(){
  fast();
  int n,k,p;
  cin >> n >> k >> p;
  //dp[vector] = mincostみたいなものを考えたい
  vector<ll> c(n);
  vector<vector<int>> a(n,vector<int>(k));
  rep(i,n){
    cin >> c[i];
    rep(j,k){
      cin >> a[i][j];
    }
  }
  map<vector<int>,ll,greater<vector<int>>> dp; //dp[arr] = mincost
  //vectorの要素の種類はたかだか6^5=7776個
  vector<int> tmp(k,0); //まず0で入れ、そのあと使い回す
  ll cost;
  dp[tmp] = 0;
  //全パターン試す
  rep(i,n){
    for(auto elem: dp){
      tmp = elem.first;
      cost = elem.second;
      rep(j,k){
        tmp[j] = min(p,tmp[j]+a[i][j]);
      }
      cost += c[i];
      if(!dp.count(tmp) || dp[tmp] > cost){
        dp[tmp] = cost;
      }
    }
  }
  vector<int> ans(k,p);
  if(!dp.count(ans)){
    cout << -1 << endl;
  }else{
    cout << dp[ans] << endl;
  }
  
}