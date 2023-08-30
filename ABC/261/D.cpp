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

//問題文：https://atcoder.jp/contests/abc261/tasks/abc261_d
/*
解答方針
本制約のうえでボーナスのないコイントスをするぶんにはすべて表であれば最大値がとれるが、ボーナスという概念があるためそうはいかない。
コイントスの回数とカウンタを記録したうえで計算していきたい。これは動的計画法でできる。
//dp[i][j] -> i回目のコイントスを行った際にカウンタがjのときの獲得金額の最大値 として考えよう。
コインが表であったときと裏であったときで遷移していけばよい。
ここで、カウンタをインデックスとしてボーナスの値をあらかじめ配列にしておくと楽である。ボーナスの種類はたかだか5000個であるため、前処理には時間がかからない。
最後に求めるべき答えはN回振ったときの各カウンタにおける最大値である。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> x(n);
  rep(i,n){
    cin >> x[i];
  }
  vector<int> c(m), y(m);
  vector<int> bonus(n+1,0); //ボーナス値を配列にしておく、要素はたかだか5000個
  rep(i,m){
    cin >> c[i] >> y[i];
    bonus[c[i]] = y[i];
  }
  vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
  //dp[i][j] -> i回目のコイントスを行った際にカウンタがjのときの獲得金額の最大値
  rep(i,n){
    rep(j,i+1){
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + x[i] + bonus[j+1]); //表, x[i]を獲得し, bonus[j+1]を獲得（カウンタはj+1になるので）
      dp[i+1][0] = max(dp[i+1][0], dp[i][j]); //裏
    }
  }
  ll ans = 0;
  rep(i,n+1){
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
  /*rep(i,n+1){
    rep(j,n+1){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
}