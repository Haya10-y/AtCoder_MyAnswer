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

/*
解答方針
もちろんループを回して求めてもよいが、今回は検索対象の文字列が"ab"と"ba"に限定されていることから、
stringのfind関数を使うことで存在の判定を行う。
対象文字列が存在しなかった場合はstring::nposを返すため、これを判定することで文字列の存在を確認できる。
*/

int main(){
  int n;
  string s;
  cin >> n >> s;
  if(s.find("ab") != string::npos){
    cout << "Yes" << endl;
  }else if(s.find("ba") != string::npos){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}