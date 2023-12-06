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

/*
解答方針
重要な性質として、k個のコンテストを取った際には、どのコンテストをとってもkについて分母は同じである。
そのため、いったん分子のみを考え、分母に関しては最後に考えるものとする。
分子について考えるということは、k個とった際の分子の最大値を考えるということになる。
これはDPを使うことで効率的に求めることができる。
右にあるコンテストほど補正倍率が高くなるため、右から順番にDPし、分子の値を求めていく。
dp[i][j] -> i番目までにj個とったときの分子の最大値 とし、O(N^2)のDPを行う。
DPが終わったら、DPテーブルの各要素ごとに最終レーティングを求める。このレーティングの最大値が答えとなる。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<ld> p(n);
  rep(i,n){
    cin >> p[i];
  }
  
  //とりあえずDP、dp[i][j] -> i番目までにj個とったときの分子の最大値
  //一番右が1倍になるので、右からDP
  vector<vector<ld>> dp(n+1, vector<ld>(n+1,0));
  
  //右からDPする
  rep_r(i,n){
    rep(j,n){
      dp[i][j] = max(dp[i][j], dp[i+1][j]); //とらないとき そのままか、ひとつ右からとってくるか
      if(i < n-j)dp[i][j+1] = max(dp[i][j+1], dp[i+1][j]+p[i]*pow(0.9d,j)); //とるとき そのままか、ひとつ右からとってくるか
    }
  }
  ld maxrate = -1e5;
  ld denominator = 0;
  ld sub = 0;
  /*rep(i,n+1){
    rep(j,n+1){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  rep(i,n){
    denominator = 0;
    rep_s(j,1,n+1){
      sub = 1200.0d / sqrtl(j);
      denominator += pow(0.9d,j-1);
      //cout << dp[i][j] << " " << denominator << " " << dp[i][j]/denominator << endl;
      maxrate = max(maxrate, dp[i][j]/denominator - sub);
    }
  }
  cout << fixed << setprecision(15) << maxrate << endl;
}