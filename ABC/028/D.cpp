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

/*
解答方針
実装力のいらない、単純な確率計算の問題。
中央値がKとなるとき、{K未満, K, Kより大きい}, {K, K, Kより大きい or 小さい}, {K, K, K}のようなパターンが考えられる。
これらを場合分けして求めていこう。
前提として、K未満の数はK-1個、Kより大きい数はN-K個あり、これらの個数の和は当然N-1個になる。
Kが1回出たうえでK未満、Kより大きい数が両方出る確率は(3P3)(k-1)(n-k)/(n^3)となる。
Kが2回出たうえでK未満またはKより大きい数が出る確率は(3C2)(n-1)(n^3)となる。
Kが3回出る確率は1/(n^3)となる。
あとはこれらの確率を足し合わせればよい。誤差に注意すること。
*/

int main(){
  ld n,k;
  cin >> n >> k;
  //kが1回出るとき
  ld k_1 = 6.0*(k-1)*(n-k)/(n*n*n);
  //kが2回出るとき
  ld k_2 = 3.0*(n-1) / (n*n*n);
  //kが3回出るとき
  ld k_3 = 1.0/(n*n*n);
  cout << fixed << setprecision(20) << k_1 + k_2 + k_3 << endl;
}