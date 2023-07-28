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

//問題文：https://atcoder.jp/contests/abc308/tasks/abc308_b
/*
解答方針
皿の色に対応した値段がついているかどうかを皿ごとに確かめましょう。
ある場合はその値段を、ない場合はP_0円を答えに足して合計金額を求めましょう。
O(NM)が十分間に合うので、二重ループで全探索するとよいです。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> c(n), d(m);
  vector<int> p(m+1);
  rep(i,n){
    cin >> c[i];
  }
  rep(i,m){
    cin >> d[i];
  }
  rep(i,m+1){
    cin >> p[i];
  }
  ll ans = 0;
  rep(i,n){
    bool flag = false;
    rep(j,m){
      if(c[i] == d[j]){
        ans += p[j+1];
        flag = true;
      }
    }
    if(!flag){
      ans += p[0];
    }
  }
  cout << ans << endl;
}