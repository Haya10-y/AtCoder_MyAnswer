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

//問題文：https://atcoder.jp/contests/abc307/tasks/abc307_b
/*
解答方針
Nおよび|S|が小さいため、O(N^2 * |S|)が十分通ります。
Nの二重ループで文字列を全探索し、結合したものとそのreverseが等しいか確認しましょう。
なお、i == jのときにスキップする必要があることに注意してください。
*/

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  rep(i,n){
    rep(j,n){
      if(i == j){
        continue;
      }
      string t = s[i]+s[j];
      string t_rev = t;
      reverse(all(t_rev));
      if(t == t_rev){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}