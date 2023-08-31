#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)

//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc194/tasks/abc194_c
/*
解答方針
まず、差の2乗を展開して考えてみる。
(A_i-A_j)^2 = (A_i)^2 - 2*A_i*A_j + (A_j)^2となる。
このとき、たとえばi,j,k,lの4変数で考えたとき、
2乗和のマイナス部分は2*A_i*A_j+2*A_i*A_k+2*A_i*A_l+2*A_j*A_k+2*A_j*A_k+2*A_k*A_lとなる。
これは括弧でくくることでもっと楽に求めることができ、たとえば
2*(A_i*(A_j+A_k+A_l)+A_j*(A_k+A_l)+A_k*A_l)となる。
このとき、括弧で囲っている和の部分は累積和を用いてO(1)で求めることができるため、
この計算をO(N)で処理することができる。
別解として-200 ~ 200までの出てくるカウントを保存して計算する方法もあるが、
数学的思考力を培いたい場合は前者の解き方だとなおよい。また、前者だとA_iの値を気にすることもない。
*/

int main(){
  fast();
  ll n;
  cin >> n;
  vector<int> a(n);
  vector<int> sum(n+1);
  sum[0] = 0;
  rep(i,n){
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
  }
  ll ans = 0;
  rep(i,n){
    ans += (n-1) * a[i] * a[i];
  }
  rep(i,n){
    ans -= 2LL * a[i] * (sum[n] - sum[i+1]);
  }
  cout << ans << endl;
}