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

//問題文：https://atcoder.jp/contests/abc294/tasks/abc294_b
/*
解答方針
与えられる行列から、みんな大好きアスキーアートを出力する問題です。
{".","A","B",...,"Z"}という配列をもって実装してもよいですし、
char型で直接計算しても問題ありません。
なお、出力例4のAAはすぬけさんのアイコンです。たぶん。
*/

int main(){
  ll h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      ll tmp;
      cin >> tmp;
      if(tmp == 0){
        a[i][j] = '.';
      }else{
        a[i][j] = (char)((int)'A'-1+tmp);
      }
    }
  }
  rep(i,h){
    rep(j,w){
      cout << a[i][j];
    }
    cout << endl;
  }
}