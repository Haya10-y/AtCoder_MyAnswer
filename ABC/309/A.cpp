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

//問題文：https://atcoder.jp/contests/abc309/tasks/abc309_a
/*
解答方針
上下への連結は聞かれていないため、そこを含めて答えないようにしましょう。
A < Bが決まっているため、aが3,6,9でない場合 (a%3 != 0) にb-aが1であるか判定すればよいです。
*/

int main(){
  int a,b;
  cin >> a >> b;
  if(a%3 != 0){
    if(b-a == 1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    cout << "No" << endl;
  }
}