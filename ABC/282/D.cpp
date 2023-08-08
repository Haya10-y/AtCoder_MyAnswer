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

//問題文：https://atcoder.jp/contests/abc282/tasks/abc282_d
/*
解答方針（後で書きます）
*/

vector<vector<ll>> g;
vector<ll> color;
bool dfs(ll v, ll cur = 0) {
    color[v] = cur;
    for (auto next_v : g[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
            continue;
        }
 
        // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
        if (!dfs(next_v , 1 - cur)) return false;
    }
    return true;
}
 
int main(){
  ll n,m;
  cin >> n >> m;
  g.resize(n);
  vector<ll> u(m),v(m);
  dsu uf(n);
  rep(i,m){
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
    uf.merge(u[i],v[i]);
  }
  vector<vector<int>> uflist = uf.groups();
  
  color.assign(n,-1);
  bool is_bipartite = true;
  rep(i,n){
    if (color[i] != -1) continue; // v が探索済みだったらスルー
    if (!dfs(i)) is_bipartite = false;
  }
  /*rep(i,n){
    cout << color[i] << " ";
  }*/
  if(!is_bipartite){
    cout << 0 << endl;
    return 0;
  }
  ll cnt = 0;
  if(sz(uflist) >= 3){
    vector<ll> lst;
    for(auto i:uflist){
      lst.push_back(sz(i));
    }
    vector<ll> sum(sz(lst)+1);
    sum[0] = 0;
    rep(i,sz(lst)){
      sum[i+1] = lst[i] + sum[i];
    }
    rep(i,sz(lst)){
      cnt += lst[i] * (sum[sz(lst)] - sum[i+1]);
    }
    for(auto i:uflist){
      ll wcnt = 0;
      ll bcnt = 0;
      for(auto j:i){
        if(color[j]){
          wcnt++;
        }else{
          bcnt++;
        }
      }
      cnt += wcnt * bcnt;
    }
    cnt -= m;
    cout << cnt << endl;
    return 0;
  }
  if(sz(uflist) == 2){
    cnt = sz(uflist[0])*sz(uflist[1]);
    ll wcnt = 0;
    ll bcnt = 0;
    rep(i,sz(uflist[0])){
      if(color[uflist[0][i]]){
        wcnt++;
      }else{
        bcnt++;
      }
    }
    cnt += wcnt*bcnt;
    wcnt = 0;
    bcnt = 0;
    rep(i,sz(uflist[1])){
      if(color[uflist[1][i]]){
        wcnt++;
      }else{
        bcnt++;
      }
    }
    cnt += wcnt*bcnt;
    cnt -= m;
    cout << cnt << endl;
    return 0;
  }
  //連結が1つのとき
  if(sz(uflist) == 1){
    cnt = 0;
    ll wcnt = 0;
    ll bcnt = 0;
    rep(i,n){
      if(color[i] == 0){
        wcnt++;
      }else{
        bcnt++;
      }
    }
    cnt = wcnt * bcnt;
    cout << cnt-m << endl;
  }
  
}