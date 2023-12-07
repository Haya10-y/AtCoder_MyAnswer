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
#define mint modint998244353;

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
消費者ごとにシミュレーションを行っていては到底間に合わない。
そこで、被覆数を高速に計算できるimos法を用いる。
imos法はこちらを参照→https://imoz.jp/algorithms/imos_method.html
絵の具の色の数は固定されているため、コンテナの要素数は1000001個になる。
絵の具aのカウントを1足し、絵の具b+1のカウントを1引くことを各消費者に対して行い、
その後累積和を行うことで答えを求めることができる。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<int> imos(1000002); //0-1000001
  rep(i,n){
    int a,b; //a,bは0-indexed
    cin >> a >> b;
    imos[a]++;
    imos[b+1]--;
  }
  int sum = 0;
  int ans = 0;
  rep(i,1000002){
    sum += imos[i];
    ans = max(ans,sum);
  }
  cout << ans << endl;
}