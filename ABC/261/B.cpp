#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

//問題文：https://atcoder.jp/contests/abc261/tasks/abc261_b
/*
解答方針
対戦結果を二次元配列としてとります。
このとき、a[i][j]と対になるものはa[j][i]です。
a[i][j]がW / L / Dのときa[j][i]がL / W / Dであれば矛盾がなく、それ以外では矛盾しています。
また、i == jのときは考えないよう気をつけましょう。
最後まで矛盾がなければcorrect、矛盾がひとつでもあればincorrectです。
*/

int main(){
  ll n;
  cin >> n;
  vector<vector<char>> a(n,vector<char>(n));
  rep(i,n){
    string s;
    cin >> s;
    rep(j,n){
      a[i][j] = s[j];
      //cerr << a[i][j] << " ";
    }
    //cerr << endl;
  }
  
  rep(i,n){
    rep(j,n){
      if((a[i][j] == 'D' && a[j][i] == 'D') || (a[i][j] == 'W' && a[j][i] == 'L') || (a[i][j] == 'L' && a[j][i] == 'W') || i==j){
        continue;
      }else{
        debug_t(i,j);
        cout << "incorrect" << endl;
        return 0;
      }
    }
  }
  cout << "correct" << endl;
}