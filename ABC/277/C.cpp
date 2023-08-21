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

//問題文：https://atcoder.jp/contests/abc277/tasks/abc277_c
/*
解答方針
グラフ理論っぽい問題です。実際、グラフ理論で解けます。
はしごはN本あり、かつビルの階層は10^9階です。
このとき、ビルの階層ひとつひとつをグラフの頂点として処理してしまうと、残念ながらTLEしてしまいます。
そこで、「はしごはN本である」という情報を使います。
はしごはN本であるということは、はしごで繋がっている頂点数は最大2N個になります。
このとき、この2N個以外の情報は全く不要であり、省くことができます。
これは座標圧縮により行うことができます。座標の小さい方から順番に0,1,2,3,4,...としてやりましょう。
あとはDFS, BFS, Union-Findなどで解くことができます。
答えを求めるとき、座標の復元を忘れないようにしてください。
このDiffに対してはかなり難しい問題であるため、心してかかりましょう。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  map<ll,ll> mp;
  mp[1]++;
  rep(i,n){
    cin >> a[i] >> b[i];
    mp[a[i]]++;
    mp[b[i]]++;
  }
  ll idx = 0;
  for(auto i = mp.begin(); i != mp.end(); i++){
    i->second  = idx;
    //cout << i->first << " " << i-> second << endl;
    idx++;
  }
  dsu uf(sz(mp)+1);
  rep(i,n){
    //cout << mp[a[i]] << " " << mp[b[i]] << endl;
    uf.merge(mp[a[i]], mp[b[i]]);
  }
  
  vector<vector<int>> v = uf.groups();
  ll num = -1;
  rep(i,sz(v)){
    rep(j,sz(v[i])){
      //cout << v[i][j] << " ";
      if(v[i][j] == 0){
        //cout << *max_element(all(v[i])) << endl;
        //return 0;
        num = *max_element(all(v[i]));
        //cout << num << endl;
        break;
      }
      if(num != -1){
        break;
      }
    }
    //cout << endl;
  }
  vector<pair<ll,ll>> v_mp(all(mp));
  rep(i,sz(v_mp)){
    if(v_mp[i].second == num){
      cout << v_mp[i].first << endl;
      return 0;
    }
  }
}