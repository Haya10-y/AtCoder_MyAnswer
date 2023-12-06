#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
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
やや特殊な解き方になるが、すべての基本を詰めているので覚えて損はないと思う。
Aの要素のうちA_iより大きな要素の和を求めたいが、いちいち要素の和を求めているとO(N^2)かかってしまいTLEする。
そのため、和の取得をO(NlogN)でとるなど工夫する必要がある。
ここで、Aをソートした配列としてBを別に用意する。このとき、要素の和に関しては累積和によって前処理O(N)、クエリごとにO(1)でとることができる。
A_iより大きな最初の要素の位置も二分探索 (upper_bound) によって簡単にとることができ、計算量はクエリごとにO(logN)、全体ではO(NlogN)でとれる。
総合的には二分探索と累積和を用いることでこの問題をO(NlogN)で解くことができる。
*/

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<ll> b = a;
  sort(all(b));
  vector<ll> sum(n+1,0);
  rep(i,n){
    sum[i+1] = sum[i]+b[i];
  }
  rep(i,n){
    auto iter = upper_bound(all(b),a[i]);
    int idx = distance(b.begin(), iter);
    //cout << idx << " ";
    cout << sum[n]-sum[idx] << " ";
  }
  cout << endl;
}