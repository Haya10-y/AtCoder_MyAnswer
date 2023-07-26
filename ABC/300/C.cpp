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

//問題文：https://atcoder.jp/contests/abc300/tasks/abc300_c
/*
解答方針
バツ印の中心から見ると、斜め4方向に#があることがわかる。
そのため、その条件が満たされる点から徐々に外側に広げていくことでバツ印のレベルを判定できる。
また、バツ印が隣り合うことがないため、中心以外で斜め4方向に#があることはまずありえない。
あとはmapでもvectorでもなんでもよいので、カウンタに記録して出力すればよい。
*/

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }
  map<ll,ll> mp;
  rep(i,h){
    rep(j,w){
      if(c[i][j] == '#'){
        int level = 1; //便宜上1とおく
        while(true){
          if(i+level >= h || i-level < 0 || j+level >= w || j-level < 0) break;
          if(c[i+level][j+level] == '#' && c[i-level][j+level] == '#' && c[i+level][j-level] == '#' && c[i-level][j-level] == '#'){
            level++;
          }else{
            break;
          }
        }
        if(level >= 2){
          mp[level-1]++;
        }
      }
    }
  }
  rep(i,min(h,w)){
    cout << mp[i+1] << " ";
  }
  cout << endl;
}