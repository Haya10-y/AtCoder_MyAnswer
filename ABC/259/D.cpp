#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define debug_st(x,y) cerr << x << " " << y << " "
#define debug_p(p) cerr << p.first << " " << p.second << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
#define mod1 998244353
#define mod2 1000000007

//問題文：https://atcoder.jp/contests/abc259/tasks/abc259_d
/*
解答方針
円同士のつながりを判定する問題です。円同士が隣接しているかどうかは距離関数をつかうことで判定できます。
また、円をグラフにおけるノードと考えることで、グラフ理論のアルゴリズム・データ構造を使うことができます。
今回だとUnion-Findが簡単です。円をノードとし、隣接しているものを繋げていきましょう。
点s, tがどの円にあるのか判定したうえで、sとtが連結であるかどうか判定すればこの問題に正解できます。
*/

ld dist(ld x,ld y, ld x2, ld y2){
  return sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2));
}

int main(){
  ll n;
  cin >> n;
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  vector<ll> x(n),y(n),r(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> r[i];
  }
  dsu uf(n);
  rep(i,n){
    rep_s(j,i+1,n){
      ld dist_tmp = dist((ld)x[i],(ld)y[i],(ld)x[j],(ld)y[j]);
      if(dist_tmp > abs(r[i]+r[j]) || dist_tmp < abs(r[i]-r[j])){
        continue;
      }
      uf.merge(i,j);
    }
  }
  vector<vector<int>> g = uf.groups();
  /*rep(i,sz(g)){
    rep(j,sz(g[i])){
      cout << g[i][j] << " ";
    }
    cout << endl;
  }*/
  ll connected_s = -1;
  ll connected_e = -1;
  rep(i,n){
    if(dist((ld)sx,(ld)sy,(ld)x[i],(ld)y[i]) == r[i]){
      connected_s = i;
    }
    if(dist((ld)tx,(ld)ty,(ld)x[i],(ld)y[i]) == r[i]){
      connected_e = i;
    }
  }
  rep(i,sz(g)){
    sort(all(g[i]));
    if(binary_search(all(g[i]),connected_s) && binary_search(all(g[i]),connected_e)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}