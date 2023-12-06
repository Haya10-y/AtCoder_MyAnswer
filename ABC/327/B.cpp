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
Bが与えられるので、A^AがBとなるAを探す問題。
ここでB <= 10^18であるため、A^A <= 10^18となる最大のAをまずは決めたい。
実際に計算するとA <= 15であることがわかるため、1^1から15^15まで確認するだけでよい。
pow関数は浮動小数点数での演算になるためやや危険である。そのため、べき乗関数を自作するかループでA^Aを求めるとよい。
*/

long long pow_ll(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
  ll b;
  cin >> b;
  //15^15までチェック
  rep_s(i,1,16){
    if(pow_ll(i,i) == b){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}