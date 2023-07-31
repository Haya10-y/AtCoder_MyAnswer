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

//問題文：https://atcoder.jp/contests/abc300/tasks/abc300_e
/*
実装方針
1~6が当確率で出るサイコロを振り、出た目の積が持っている数になりえるかどうかまず判定したい。
これは素因数分解を使うことで判定できる。7以上の目はないため、5まで素因数分解すれば十分である。
分解しきれたら次に進み、できなければその場で終了する。
素因数分解ができた場合は2の個数、3の個数、5の個数を把握しておく。
ここで確率DPを使い、全操作終了後に持っている整数がNになる確率を求める。
なお、確率はfloatやdoubleでなく、modintで計算すればよい。計算のしかたはfloatやdoubleと同様。
dp[i][j][k] -> 2がi回、3がj回、5がk回出る期待値とし、遷移を行う。
ただし4が出たときは2が2回、6が出たときは2と3が1回ずつ出たものとして扱う。
1が出たときは振り直しであるため、ここは考えなくてよい。
全てが0であるときの確率を1とし、出た目の数に対してすべて遷移させよう。
最終的な答えはdp[2の個数][3の個数][5の個数]である。
*/

//素因数分解を改造、5までやる（1-6までの数しかかけないので7以上はない）
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a <= 5; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数
 
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
 
        // その結果を push
        res.push_back({a, ex});
    }
 
    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
 
int main(){
  ll n;
  cin >> n;
  auto prime = prime_factorize(n);
  if(prime[sz(prime)-1].first >= 6){ //7以上の数がある場合
    cout << 0 << endl;
    return 0;
  }
  map<ll,ll> mp; //要素数は最大で3
  for(auto i:prime){
    mp[i.first] = i.second;
  }
  vector<vector<vector<mint>>> dp(mp[2]+1, vector<vector<mint>>(mp[3]+1, vector<mint>(mp[5]+1, 0)));
  dp[0][0][0] = 1;
  //cout << mp[2] << " " << mp[3] << " " << mp[5] << endl;
  rep(i,mp[2]+1){
    rep(j,mp[3]+1){
      rep(k,mp[5]+1){
        //2-6においてやる
        if(i+1 <= mp[2])dp[i+1][j][k] = dp[i+1][j][k] + dp[i][j][k] / 5;
        if(j+1 <= mp[3])dp[i][j+1][k] = dp[i][j+1][k] + dp[i][j][k] / 5;
        if(i+2 <= mp[2])dp[i+2][j][k] = dp[i+2][j][k] + dp[i][j][k] / 5;
        if(k+1 <= mp[5])dp[i][j][k+1] = dp[i][j][k+1] + dp[i][j][k] / 5;
        if(i+1 <= mp[2] && j+1 <= mp[3])dp[i+1][j+1][k] = dp[i+1][j+1][k] + dp[i][j][k] / 5;
      }
    }
  }
  cout << dp[mp[2]][mp[3]][mp[5]].val() << endl;
}