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

//問題文：https://atcoder.jp/contests/abc291/tasks/abc291_d
/*
解答方針
ありうるパターン数を聞かれているため、DPを使うことをまず視野に入れる。
dp[i][j][k]をi枚目が表/裏(j=0,1)、i+1枚目が表/裏(k=0,1)のときのパターン数として計算してみよう。
表表の場合はa[i]とa[i+1]を比較し違っていたら遷移、
表裏の場合はa[i]とb[i+1]を比較し違っていたら遷移…というようにやってみよう。
最終的な答えは0 <= i <= 1かつ0 <= j <= 1のときのdp[n-1][i][j]の総和。
あくまで自己流の解き方なので、もっと解きやすい方法があるかもしれない。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(2,0))); 
  if(n == 1){
    cout << 2 << endl;
    return 0;
  }
  //dp[i][j][k]: i枚目が表/裏(j=0,1)、i+1枚目が表/裏(k=0,1)のときのパターン数
  if(a[0] != a[1]){
    dp[1][0][0] = 1;
  }
  if(a[0] != b[1]){
    dp[1][0][1] = 1;
  }
  if(b[0] != b[1]){
    dp[1][1][1] = 1;
  }
  if(b[0] != a[1]){
    dp[1][1][0] = 1;
  }
  rep_s(i,1,n-1){
    if(a[i] != a[i+1]){
      dp[i+1][0][0] += dp[i][0][0];
      dp[i+1][0][0] += dp[i][1][0];
      dp[i+1][0][0] %= mod1;
    }
    if(a[i] != b[i+1]){
      dp[i+1][0][1] += dp[i][0][0];
      dp[i+1][0][1] += dp[i][1][0];
      dp[i+1][0][1] %= mod1;
    }
    if(b[i] != b[i+1]){
      dp[i+1][1][1] += dp[i][0][1];
      dp[i+1][1][1] += dp[i][1][1];
      dp[i+1][1][1] %= mod1;
    }
    if(b[i] != a[i+1]){
      dp[i+1][1][0] += dp[i][0][1];
      dp[i+1][1][0] += dp[i][1][1];
      dp[i+1][1][0] %= mod1;
    }
  }
  ll ans = (dp[n-1][0][0]+dp[n-1][0][1]+dp[n-1][1][0]+dp[n-1][1][1])%mod1;
  cout << ans << endl;
}