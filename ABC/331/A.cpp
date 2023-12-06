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
繰り上げの問題。
d+1がDを上回ってしまった場合、繰り上げが発生してmに1を足す。このときdは1になる。
ここでさらにmがMを上回った場合、ここでも繰り上げが発生してyに1を足す。このときmは1になる。
計算後の最終的なy, m, dをスペース区切りで出力すればよい。
*/

int main(){
  int M,D,y,m,d;
  cin >> M >> D >> y >> m >> d;
  d++;
  if(d > D){
    d = 1;
    m++;
  }
  if(m > M){
    m = 1;
    y++;
  }
  cout << y << " " << m << " " << d << endl;
}