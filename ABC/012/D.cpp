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

/*
解答方針
典型的なダイクストラ法の問題。
ひねった解答は要求されないので、練習だと思ってやってみよう。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m),b(m);
  vector<ll> t(m);
  set<ll> p;
  vector<vector<pair<ll,ll>>> g(n);
  rep(i,m){
    cin >> a[i] >> b[i] >> t[i];
    a[i]--;
    b[i]--;
    p.insert(a[i]);
    p.insert(b[i]);
    g[a[i]].push_back(make_pair(t[i],b[i])); //priority_queueのためコストが先
    g[b[i]].push_back(make_pair(t[i],a[i]));
  }
  ll ans = INFINITY;
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> dijkstra;
  for(auto i: p){
    vector<ll> dist(n,INFINITY);
    dist[i] = 0;
    dijkstra.push(make_pair(0,i));
    while(!dijkstra.empty()){
      ll node = dijkstra.top().second;
      ll cost = dijkstra.top().first;
      dijkstra.pop();
      if(dist[node] < cost){
        continue;
      }
      for(auto j: g[node]){
        if(dist[j.second] > cost + j.first){
          dist[j.second] = cost + j.first;
          dijkstra.push(make_pair(dist[j.second],j.second));
        }
      }
    }
    ll mx = *max_element(all(dist));
    ans = min(mx,ans);
  }
  cout << ans << endl;
  return 0;
}