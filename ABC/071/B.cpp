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

/*
解答方針
すべての英小文字について、それが存在しているか確認しよう。
（英小文字）-'a'とすればaを0番目としたときに何番目のアルファベットであるか指定できる。
文字列Sをすべて走査したら、aからzまで順番に文字が存在していたかチェックする。
存在していなかった時点で打ち切ってその文字を出力し、全て存在していたらNoneを出力。
*/

int main(){
  string s;
  cin >> s;
  int n = (int)(s.size());
  vector<bool> exist(26,false);
  rep(i,n){
    exist[(int)(s[i]-'a')] = true;
  }
  rep(i,26){
    if(!exist[i]){
      cout << (char)((int)'a'+i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}