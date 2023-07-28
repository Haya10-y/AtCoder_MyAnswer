#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (int bit = 0; bit < (1<<n); bit++)
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

//問題文：https://atcoder.jp/contests/abc311/tasks/abc311_e
/*
解答方針
正方形をつくる問題として最初に思いついたのが最大正方形問題である。
最大正方形問題についてはここがわかりやすい→https://qiita.com/H20/items/884551b4965739176afc
DPをつかってその点における正方形の最大面積（実際は1辺の長さ）を求める。
この最大面積は実際、そこに置ける正方形の数と一致するため、あとはこれらの総和を求めることで解くことができる。
計算量はO(HW+N)になる。
*/

int main(){
  fast();
  int h,w,n;
  cin >> h >> w >> n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  vector<vector<bool>> tile(h,vector<bool>(w,true));
  rep(i,n){
    tile[a[i]][b[i]] = false;
  }
  vector<vector<int>> dp(h,vector<int>(w,0));
  rep(i,h){
    rep(j,w){
      int maxsize = 100000;
      if(i == 0 && j == 0){
        if(tile[i][j])dp[i][j] = 1;
        continue;
      }
      if(j-1>=0){
        maxsize = min(maxsize,dp[i][j-1]);
      }else{
        maxsize = 0;
      }
      if(i-1>=0){
        maxsize = min(maxsize,dp[i-1][j]);
      }else{
        maxsize = 0;
      }
      if(j-1>=0 && i-1>=0){
        maxsize = min(maxsize,dp[i-1][j-1]);
      }else{
        maxsize = 0;
      }
      if(!tile[i][j]){
        dp[i][j] = 0;
      }else{
        dp[i][j] = maxsize+1;
      }
    }
  }
  ll ans = 0;
  rep(i,h){
    rep(j,w){
      ans += dp[i][j];
    }
  }
  cout << ans << endl;
}