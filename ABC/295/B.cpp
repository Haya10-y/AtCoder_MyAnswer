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

//問題文：https://atcoder.jp/contests/abc295/tasks/abc295_b
/*
解答方針
爆弾の爆発範囲について考えることが必要になります。
盤面を全探索し、爆弾マスがあれば爆破していきましょう。
ただし、爆破の段階で別の爆弾を破壊しないように注意しましょう。
半径をとり、現在のマスと目的のマスとのマンハッタン距離が半径以下であれば壁を破壊しましょう。
これはループと条件分岐で行うことができます。
爆破処理が終わった段階で爆弾を消すことを忘れないようにしましょう。
*/

int main(){
  fast();
  int r,c;
  cin >> r >> c;
  vector<vector<char>> b(r,vector<char>(c));
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> b[i][j];
    }
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if('1' <= b[i][j] && b[i][j] <= '9'){
        //爆発処理
        int radius = (int)(b[i][j]-'0');
        for(int k = max(i-radius,0); k < min(i+radius+1, r); k++){
          for(int l = max(j-radius,0); l < min(j+radius+1, c); l++){
            if(abs(i-k)+abs(j-l) > radius){
              continue;
            }
            if(b[k][l] == '#'){
              b[k][l] = '.';
            }
          }
        }
        b[i][j] = '.';
      }
    }
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout << b[i][j];
    }
    cout << endl;
  }
}