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

//問題文：https://atcoder.jp/contests/abc302/tasks/abc302_c
/*
解答方針
N <= 8であることから、やや特殊な探索をすることがまず考えられる。
この問題では順列全探索を用いることで正解することができる。
ありうる文字列の並び替えをすべて行い、条件を満たすか愚直に判定することでO(NM*N!)でこの問題に正解できる。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  sort(all(s));
  while(true){
    rep(i,n-1){
      int cnt = 0;
      rep(j,m){
        if(s[i][j] != s[i+1][j]){
          cnt++;
        }
      }
      if(cnt != 1){
        break;
      }
      if(i == n-2){
        cout << "Yes" << endl;
        return 0;
      }
    }
    if(!next_permutation(all(s))){
      break;
    }
  }
  cout << "No" << endl;
}