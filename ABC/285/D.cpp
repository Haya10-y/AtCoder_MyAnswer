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

//問題文：https://atcoder.jp/contests/abc285/tasks/abc285_d
/*
解答方針
一度、"S_iからT_iに変更したい"ということを図に起こしてみよう。
そうすると、できた図は有向グラフになることがわかる。
ここで条件を満たさない場合を考えてみよう。
a -> b -> c -> a -> ...といった、ずっと循環し続けるような部分があるときユーザーネームを変更できないことがわかる。
これはグラフ用語ではサイクルといい、これがあるか検出できるアルゴリズムとしてトポロジカルソートがある。
実装においてはユーザ名にIDを振り、int型で処理するとよい。座標圧縮に近い考え方になる。
つまりこの問題は"座圧してトポロジカルソート"という問題に置き換わる。少し難しいががんばってみよう。
*/

int main(){
  ll n;
  cin >> n;
  vector<string> s(n),t(n);
  rep(i,n){
    cin >> s[i] >> t[i];
  }
  //str to numによりグラフ問題に帰着
  map<string,ll> strtonum;
  ll cnt = 0;
  vector<ll> s_num(n), t_num(n);
  rep(i,n){
    if(!strtonum.count(s[i])){
      strtonum[s[i]] = cnt;
      cnt++;
    }
    if(!strtonum.count(t[i])){
      strtonum[t[i]] = cnt;
      cnt++;
    }
  }
  rep(i,n){
    s_num[i] = strtonum[s[i]];
    t_num[i] = strtonum[t[i]];
  }
  /*rep(i,n){
    cout << s_num[i] << " " << t_num[i] << endl;
  }*/
  //toposort
  ll siz = sz(strtonum);
  vector<vector<ll>> g(siz);
  rep(i,n){
    g[s_num[i]].push_back(t_num[i]);
  }
  vector<ll> ans;
  vector<ll> indeg(siz);
  rep(i,n){
    indeg[t_num[i]]++;
  }
  queue<ll> bfs;
  rep(i,siz){
    if(indeg[i] == 0){
      bfs.push(i);
    }
  }
  while(!bfs.empty()){
    ll now = bfs.front();
    ans.push_back(now);
    bfs.pop();
    for(auto i: g[now]){
      indeg[i]--;
      if(indeg[i] == 0){
        bfs.push(i);
      }
    }
  }
  /*rep(i,sz(ans)){
    cout << ans[i] << " ";
  }
  cout << endl;*/
  if(sz(strtonum) == sz(ans)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}