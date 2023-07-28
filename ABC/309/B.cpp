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

//問題文：https://atcoder.jp/contests/abc309/tasks/abc309_b
/*
解答方針
多少の考察と、実装力を要求される問題です。
ひとつ考えられることとして、左端と右端が繋がっている配列の隣り合う要素をスワップしていくと最終的に元に戻るということがあります。
そのため、端の要素をスワップしていくことで解くことができます。
配列aの要素はstring型でとるより、vector<char>型でとったほうが私的には好みです。
テストの際は大きめの配列や、0,1以外が入ったもので試してみるとよいでしょう。
*/

int main(){
  int n;
  cin >> n;
  vector<vector<char>> a(n,vector<char>(n));
  rep(i,n){
    rep(j,n){
      cin >> a[i][j];
    }
  }
  rep(i,n-1){
    swap(a[i][0],a[i+1][0]);
  }
  rep(i,n-1){
    swap(a[n-1][i],a[n-1][i+1]);
  }
  rep_rs(i,n,1){
    swap(a[i][n-1],a[i-1][n-1]);
  }
  rep_rs(i,n,2){
    swap(a[0][i],a[0][i-1]);
  }
  rep(i,n){
    rep(j,n){
      cout << a[i][j];
    }
    cout << endl;
  }
}