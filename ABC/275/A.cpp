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
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define debug_st(x,y) cerr << x << " " << y << " "
#define debug_p(p) cerr << p.first << " " << p.second << endl
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

//問題文：https://atcoder.jp/contests/abc275/tasks/abc275_a
/*
解答方針
橋がN本あり、どの橋も高さが異なります。このとき、どの橋が一番高いかということを答える問題です。
橋の高さの最大値とその橋の番号をもち、ひとつずつ処理していきましょう。
配列は使っても使わなくても大丈夫です。慣れないうちは最初に入力を配列に
すべて入れたあとに処理していきましょう。
*/

int main(){
  fast();
  int n,h;
  int ans = 0;
  int max = -1;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> h;
    if(max < h){
      ans = i+1;
      max = h;
    }
  }
  cout << ans << endl;
}