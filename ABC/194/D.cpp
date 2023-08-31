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

//問題文：https://atcoder.jp/contests/abc194/tasks/abc194_d
/*
解答方針
よく考えてみよう。
各頂点が選ばれる確率は1/Nであり、また操作は独立である。
さらに、高橋君がいる頂点は絶対に最大の連結成分中にあり、またそれ以外はすべて孤立している。
このことから、「平均何回でまだ孤立している点をひとつとれるか」ということを考えていけばよい。
残った頂点数について考えたとき、i回目 (1 <= i <= N-1) に新しい頂点を選ぶまでにかかる平均回数はN/(N-i)回となる。
これを足していくことですべての頂点を連結させたときの操作回数の期待値を求めることができる。
*/

int main(){
  fast();
  int n;
  cin >> n;
  ld ans = 0;
  rep_s(i,1,n){
    ans += (ld)n / (ld)i;
  }
  cout << fixed << setprecision(20) << ans << endl;
}