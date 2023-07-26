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

//問題文：https://atcoder.jp/contests/abc305/tasks/abc305_e
/*
解答方針
「その点にいる警備員の最大体力」を考えてなにかできそう。
この問題の場合、始点を1点ではなく、多点にしてスタートするいわゆる拡張ダイクストラで解ける。
体力の小さい順から埋めていったほうが効率がよい（大きい順だとqueueの要素数が爆発的に増加するため）
*/

bool comp(pair<int,int> p1, pair<int,int> p2){
  return p1.second > p2.second;
}
 
int main(){
  fast();
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(m), b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  vector<pair<int,int>> ph(k);
  rep(i,k){
    cin >> ph[i].first >> ph[i].second;
    ph[i].first--;
  }
  sort(all(ph), comp); //体力の多い順に取り出す
  vector<vector<int>> g(n);
  rep(i,m){
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  vector<int> maxhealth(n,-1);
  rep(i,k){
    maxhealth[ph[i].first] = ph[i].second; //ある点における警官の最大体力
  }
  //体力が小さい順に取り出したほうがよい…？ダイクストラっぽく解く感じ…？
  priority_queue<pair<int,int>> dijkstra;
  //最初に頂点pを全部入れていけば大丈夫そう？
  rep(i,k){
    dijkstra.push(make_pair(ph[i].second, ph[i].first));
  }
  while(!dijkstra.empty()){
    pair<int,int> elem = dijkstra.top();
    dijkstra.pop();
    int node = elem.second;
    int hp = elem.first;
    if(hp == 0){
      continue;
    }
    for(auto j: g[node]){
      if(maxhealth[j] >= hp-1){
        continue;
      }
      maxhealth[j] = hp-1;
      dijkstra.push(make_pair(hp-1, j));
    }
  }
  int ans = 0;
  rep(i,n){
    if(maxhealth[i] != -1){
      ans++;
    }
  }
  cout << ans << endl;
  rep(i,n){
    if(maxhealth[i] != -1){
      cout << i+1 << " ";
    }
  }
  cout << endl;
}