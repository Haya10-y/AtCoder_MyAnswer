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

//問題文：https://atcoder.jp/contests/abc312/tasks/abc312_c
/*
解答方針
Xが大きくなるとどうなるか考えてみよう。
AとBを昇順ソートすることを前提として考える。
Xが大きくなると、条件を満たすAの要素数は減ることはなく（広義単調増加）、
条件を満たすBの要素数は増えることはない（広義単調減少）。
よって、このような条件下ではXの値で二分探索することにより、目的の値を求めることができる。
条件を満たすA・Bの要素数も二分探索で求めることができるため、高速に問題を解くことができる。
ソートがボトルネックとなることが多く、O(NlogN+MlogM)程度になることが多い。
探索の計算量については上限値をMAXとしたとき、O(logMAX*(logA+logB))くらいになる。
二分探索を行うときは、上限を十分大きい値にしよう。対数時間で終わるため、10^18にしてもたかだか60回あれば終わる。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n),b(m);
  rep(i,n){
    cin >> a[i];
  }
  rep(j,m){
    cin >> b[j];
  }
  sort(all(a));//昇順
  sort(all(b));//昇順
  ll low = 0;
  ll high = 2.5e9;
  ll mid = (low+high)/2;
  while(high-low > 1){
    ll x = mid;
    auto iter_a = upper_bound(all(a),x);
    auto iter_b = upper_bound(all(b),x-1);
    int dist_a = distance(a.begin(),iter_a);
    int dist_b = distance(b.begin(),iter_b);
    dist_b = m-dist_b;
    if(dist_a >= dist_b){
      high = mid;
    }else{
      low = mid;
    }
    mid = (high+low)/2;
  }
  cout << mid+1 << endl;
}