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

//問題文：https://atcoder.jp/contests/abc293/tasks/abc293_c
/*
実装方針
H,Wが小さいため、移動経路の全探索を考えたい。
こういったものの全探索をするときは再帰関数を書くと楽である。
「あるマスから下方向あるいは右方向に進み、再帰関数を呼び出す」ということを繰り返すことで
すべての経路を列挙することができる。
また、経路上の整数はsetで管理しておくと被りがあるかわかりやすい。再帰関数に渡してもsetの最大サイズがあまり大きくないので問題ない。
*/

ll h,w;
vector<vector<ll>> a;
ll ans = 0;
void searchall(ll y, ll x, set<ll> st){
  //cout << y << " " << x << endl;
  if(st.count(a[y][x])){
    return;
  }
  st.insert(a[y][x]);
  if(y+1 < h){
    searchall(y+1,x,st);
  }
  if(x+1 < w){
    searchall(y,x+1,st);
  }
  if(y == h-1 && x == w-1){
    ans++;
    return;
  }
}
 
int main(){
  cin >> h >> w;
  a.assign(h,vector<ll>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  set<ll> st;
  searchall(0,0,st);
  cout << ans << endl;
}