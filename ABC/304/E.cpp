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

//問題文：https://atcoder.jp/contests/abc304/tasks/abc304_e
/*
実装方針
頂点xとyが連結であるかどうかは、Union-Findを用いて判定することができる。
そのため、Union-Findに辺を追加したうえで、連結成分を求める。
そのあと、何番目の連結成分に頂点iがあるか、ということを0 <= i < nについて判定し、
すべての頂点x,yについて、何番目の連結成分にあるか判定し、繋げてはいけない連結成分同士の番号をとる。
これは各連結成分ごとにsetでとり、setの中には繋げてはいけない連結成分の番号を入れる。
あとはp,qを読み込み、pと繋げてはいけない連結成分の中にqがあるかどうかを確認すればよい。
p,qがある連結成分の番号はO(1)で求められる。
*/

ll distpow(ll x1, ll y1, ll x2, ll y2){
  return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
 
int main(){
  fast();
  int n,m;
  cin >> n >> m;
  vector<int> u(m),v(m);
  rep(i,m){
    cin >> u[i] >> v[i];
    u[i]--;v[i]--;
  }
  int k;
  cin >> k;
  vector<int> x(k), y(k);
  rep(i,k){
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
  }
  int Q;
  cin >> Q;
  vector<int> p(Q), q(Q);
  rep(i,Q){
    cin >> p[i] >> q[i];
    p[i]--;q[i]--;
  }
  vector<vector<int>> g(n);
  rep(i,m){
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  /*vector<vector<int>> forbidden(n);
  rep(i,k){
    forbidden[x[i]].push_back(y[i]);
    forbidden[y[i]].push_back(x[i]);
  }*/
  dsu uf(n);
  rep(i,m){
    uf.merge(u[i], v[i]);
  }
  auto group = uf.groups();
  vector<int> groupnum(n); //グループ番号をつける
  rep(i,sz(group)){
    rep(j,sz(group[i])){
      groupnum[group[i][j]] = i;
    }
  }
  
  vector<set<ll>> forbiddenset(sz(group));
  rep(i,k){
    forbiddenset[groupnum[x[i]]].insert(groupnum[y[i]]);
    forbiddenset[groupnum[y[i]]].insert(groupnum[x[i]]);
  }
  
  rep(i,Q){
    if(forbiddenset[groupnum[p[i]]].count(groupnum[q[i]])){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }
}