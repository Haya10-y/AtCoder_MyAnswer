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

//問題文：https://atcoder.jp/contests/abc266/tasks/abc266_d
/*
解答方針
和の最大値を考える問題。前の状態を見たいため、動的計画法を使って考えてみる。
dp[i][j] -> 時刻i時点で高橋くんが座標jにいたときのスコアの最大値 として考えてみよう。ただし、絶対にこの状態がありえない場合は-1とする。
高橋くんは時刻0時点で座標0にいるため、dp[0][0] = 0としてから計算しはじめよう。
時刻iに座標jにいたときのことを考えると、端以外では時刻i+1ではj-1, j, j+1に動くことができる。
すぬけ君の出てくる時刻と座標およびその大きさはvectorで管理しておこう。時刻ごとに保存しておくと呼び出しが速い。
計算量はO(N+max(T))程度であり、十分間に合う。
*/

int main(){
  fast();
  int n;
  cin >> n;
  int t,x,a;
  vector<vector<int>> snuke(100001, vector<int>(5,0));
  rep(i,n){
    cin >> t >> x >> a;
    snuke[t][x] = a;
  }
  vector<vector<ll>> dp(100001, vector<ll>(5, -1));
  dp[0][0] = 0;
  //dp[i][j] -> 時刻i時点で高橋くんが座標jにいたときのスコアの最大値
  //-1なら絶対ありえない
  rep(i,100000){
    rep(j,5){
      if(dp[i][j] == -1){
        continue;
      }
      if(j+1 <= 4)dp[i+1][j+1] = max(dp[i][j]+snuke[i+1][j+1], dp[i+1][j+1]);
      dp[i+1][j] = max(dp[i][j]+snuke[i+1][j], dp[i+1][j]);
      if(j-1 >= 0)dp[i+1][j-1] = max(dp[i][j]+snuke[i+1][j-1], dp[i+1][j-1]);
    }
    /*rep(j,5){
      cout << dp[i+1][j] << " ";
    }
    cout << endl;*/
  }
  ll ans = 0;
  rep(i,5){
    ans = max(ans,dp[100000][i]);
  }
  cout << ans << endl;
}