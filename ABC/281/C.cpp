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

//問題文：https://atcoder.jp/contests/abc281/tasks/abc281_c
/*
解答方針
Tの値が大きく、普通に解くとTLEしてしまいます。
ここで、プレイリストが1周するのに何秒かかるか考えます。これはO(N)で計算できます。
プレイリストが何周できるかはO(1)で計算可能なので、プレイリストが1周できなくなるまで時間を進め、
そこから1曲ずつ進めていけばよいです。
*/

int main(){
  ll n,t;
  cin >> n >> t;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll sum = 0;
  ll idx = 0;
  ll sum_a = 0;
  rep(i,n){
    sum_a += a[i];
  }
  t %= sum_a;
  while(true){
    if(sum <= t && t <= sum+a[idx]){
      ll ans = t-sum;
      cout << idx+1 << " " << ans << endl;
      return 0;
    }else{
      sum += a[idx];
    }
    idx++;
    idx %= n;
  }
}