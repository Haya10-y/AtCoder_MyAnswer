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

//問題文：https://atcoder.jp/contests/abc312/tasks/abc312_b
/*
解答方針
ありうる9*9のマスを全て探索し、それがTaK Codeの条件を満たすかfor文とif文で判定します。
やや実装が大変なので、頑張りましょう。
もっと楽な解き方として、TaK Codeをあらかじめプログラム中に埋め込むという方法があります。
こちらのほうがマス目に関する条件分岐の必要性が減り、もっと楽になります。
*/

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  rep(i,n-8){
    rep(j,m-8){
      int black = 0;
      int white = 0;
      rep(di,9){
        rep(dj,9){
          if((di < 3 && dj < 3) || (di >= 6 && dj >= 6)){
            if(s[i+di][j+dj] == '#')black++;
          }
          if((di == 3 && dj <= 3) || (di == 5 && dj >= 5) || (dj == 3 && di <= 3) || (dj == 5 && di >= 5)){
            if(s[i+di][j+dj] == '.')white++;
          }
        }
      }
      //cout << black << " " << white << endl;
      if(black == 18 && white == 14){
        cout << i+1 << " " << j+1 << endl;
      }
    }
  }
}