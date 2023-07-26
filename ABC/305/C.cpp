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

//問題文：https://atcoder.jp/contests/abc305/tasks/abc305_c

/*
解答方針
クッキーは必ず軸に平行な長方形の形に配置されている。
そのため、上端と下端、左端と右端をとってやればよい。
そのうえでこの区間を探索し、欠けている部分を見つければよい。
計算量はO(HW)で、十分間に合う。
*/

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
    }
  }
  //上の辺を見る
  int upper = -999;
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#'){
        upper = i;
        break;
      }
    }
    if(upper != -999)break;
  }
  //下の辺を見る
  int lower = -999;
  rep_r(i,h){
    rep(j,w){
      if(s[i][j] == '#'){
        lower = i;
        break;
      }
    }
    if(lower != -999)break;
  }
  //左の辺を見る
  int left = -999;
  rep(i,w){
    rep(j,h){
      if(s[j][i] == '#'){
        left = i;
        break;
      }
    }
    if(left != -999)break;
  }
  //右の辺を見る
  int right = -999;
  rep_r(i,w){
    rep(j,h){
      if(s[j][i] == '#'){
        right = i;
        break;
      }
    }
    if(right != -999)break;
  }
  //cout << left << " " << right << " " << upper << " " << lower << endl;
  for(int i = upper; i <= lower; i++){
    for(int j = left; j <= right; j++){
      if(s[i][j] == '.'){
        cout << i+1 << " " << j+1 << endl;
        return 0;
      }
    }
  }
}