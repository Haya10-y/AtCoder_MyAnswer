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
定食の価格は最大でもP円となる。
主菜と副菜の選び方はNM通りあり、すべて試そうとするとO(NM)でTLEする。
ここで、すべての主菜と副菜を選ぶため、順番が関係なくなることを利用し、主菜と副菜を価格の昇順にソートする。
主菜を全探索すると、定食の価格がP円未満となる副菜の価格はP-A[i]円未満である。
はじめてB[j] = P-A[i]となるをjを二分探索で探し、累積和を用いて0番目からj番目までの価格の和を求める。
残りのM-j個はP円であることが確定しているため、ここはO(1)になる。
総合的に、主菜1個につきO(logM)の計算量がかかるため、全体の計算量はO(N(logN+logM)+MlogM)程度になる。これは十分高速。
*/

int main(){
  fast();
  int n,m;
  ll p;
  cin >> n >> m >> p;
  vector<ll> a(n),b(m);
  rep(i,n){
    cin >> a[i];
  }
  rep(j,m){
    cin >> b[j];
  }
  sort(all(a));
  sort(all(b));
  ll ans = 0;
  vector<ll> sum_b(m+1,0);
  rep(i,m){
    sum_b[i+1] = sum_b[i] + b[i];
  }
  //aを全探索してbをにぶたん+累積和
  rep(i,n){
    auto iter = lower_bound(all(b),p-a[i]); //a+b >= pのときp固定なので、はじめてb >= p-aとなるidxを探す
    int idx = distance(b.begin(),iter);
    ans += (m-idx)*p; //後ろm-idx個はp円
    ans += a[i]*idx + sum_b[idx]; //前idx個はa+b円
  }
  cout << ans << endl;
}