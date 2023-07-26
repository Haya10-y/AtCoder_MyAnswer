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

//問題文：https://atcoder.jp/contests/abc310/tasks/abc310_c
/*
解答方針
ある文字列とそれを前後反転したものは同じものである。
そこで、それらのうちから辞書順で小さい方を採用することで、同じものをまとめることができる。
あとはsetに入れていき、要素数を出力するだけ。
*/

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  set<string> st;
  rep(i,n){
    string tmp = s[i];
    reverse(all(tmp));
    st.insert(min(s[i],tmp));
  }
  cout << sz(st) << endl;
}