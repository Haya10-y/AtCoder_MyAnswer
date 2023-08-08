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

//問題文：https://atcoder.jp/contests/abc281/tasks/abc281_d
/*
解答方針
dp[i][j][l] a_1~a_iまでj個選んでx mod d = lのときのmod回数とおき、a_iを選ぶ場合とa_iを選ばない場合で遷移しよう。
解き方あまり覚えていないので続きは後で書きます。
*/

int main(){
  ll n,k,d;
  cin >> n >> k >> d;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(k+1,vector<ll>(d,-1)));
  dp[0][0][0] = 0;
  //dp[i][j][l] a_1~a_iまでj個選んでx mod d = lのときのmod回数
  rep(i,n){
    rep(j,k+1){
      rep(l,d){
        if(dp[i][j][l] == -1){
          continue;
        }
        //a_iを選ばない場合
        dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
        //a_iを選んだ場合
        if(j != k){
          ll plus = (a[i]+l)/d;
          dp[i+1][j+1][(a[i]+l)%d] = max(dp[i+1][j+1][(a[i]+l)%d],dp[i][j][l]+plus);
        }
      }
    }
  }
  if(dp[n][k][0] == -1){
    d = 1;
  }
  cout << dp[n][k][0]*d << endl;
}