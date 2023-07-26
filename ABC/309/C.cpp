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

//問題文：https://atcoder.jp/contests/abc309/tasks/abc309_c
/*
解答方針
まず、1日目はすべての薬を飲まないといけません。
また、指定された日数薬を飲みきったとき、b_i錠だけ飲む必要のある薬が減ります。
このことから、aとbのペアをつくり、aについて昇順ソートして順番に処理していくことで
最初に飲む必要のある薬がK錠以下になる日数がわかります。
このとき、1日目にK錠以下になる可能性があることに気をつけてください。
*/

int main(){
  int n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> ab(n);
  rep(i,n){
    cin >> ab[i].first >> ab[i].second;
  }
  sort(all(ab));
  ll sum = 0;
  rep(i,n){
    sum += ab[i].second;
  }
  if(sum <= k){
    cout << 1 << endl;
    return 0;
  }
  rep(i,n){
    sum -= ab[i].second;
    if(sum <= k){
      cout << ab[i].first+1 << endl;
      return 0;
    }
  }
}