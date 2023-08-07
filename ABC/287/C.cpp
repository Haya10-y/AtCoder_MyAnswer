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

//問題文：https://atcoder.jp/contests/abc287/tasks/abc287_c
/*
解答方針
パスグラフとはつまり、枝分かれのないグラフのことです。
ここで考えられることとして、伸びている辺が1つだけである点から探索を行うとよいです。
この点からは絶対に枝分かれが起きず、かつ一方通行であるためパスグラフの判定がしやすいからです。
また、パスグラフであったときはこの点はグラフの端の点になります。
BFSをして、次に現れる頂点の数が2以上であったとき枝分かれがあるため、条件を満たしません。
BFSを最後まで行うことができれば枝分かれが存在せず、かつ1回のBFSですべての点を通ればパスグラフとなり、条件を満たします。
次に現れる頂点の数は随時初期化して記録しておきましょう。
また、パスグラフとなる場合はM = N-1となることが絶対であるため、そうでない場合は早々に切り上げても問題ありません。
なお、この問題では枝分かれを判定したいため、DFSよりBFSのほうがよい可能性が大いにあります。
*/

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  rep(i,m){
    ll u,v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll start = -1;
  rep(i,n){
    if(sz(g[i]) == 1){
      start = i;
      break;
    }
  }
  if(start == -1){
    cout << "No" << endl;
    return 0;
  }
  queue<ll> bfs;
  bfs.push(start);
  //ll prev = -1;
  vector<bool> seen(n,false);
  seen[start] = true;
  while(!bfs.empty()){
    ll node = bfs.front();
    bfs.pop();
    ll cnt = 0;
    for(auto i: g[node]){
      
      if(seen[i]){
        continue;
      }
      cnt++;
      if(cnt >= 2){
        cout << "No" << endl;
        return 0;
      }
      seen[i] = true;
      bfs.push(i);
    }
  }
  rep(i,n){
    if(!seen[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}