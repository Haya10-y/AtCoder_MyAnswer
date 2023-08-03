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
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc296/tasks/abc296_b
/*
解答方針
まず、チェス盤の何行何列目にコマがあるのか判定しましょう。
判定できたら、フォーマットに従って答えを出力します。
ただし、列は左からa,b,c,d,e,f,g,hであり、行は上から8,7,6,5,4,3,2,1であることに注意してください。
配列に埋め込んでもいいですし、直接計算して求めても構いません。
*/

int main(){
  ll n = 8;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  ll r,c;
  rep(i,n){
    rep(j,n){
      if(s[i][j] == '*'){
        r = i;
        c = j;
      }
    }
  }
  cout << (char)('a'+c) << 8-r << endl;
}