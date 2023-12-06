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
整数列から欠けた整数、けつばんを見つけたい。
整数列をソートし、下から順番に見ていく。
制約上、差が1でないところが確定でけつばんになるので、そこを出力すればよい。
なお、サンプルケース3についてだが、けつばんは152番目のポケモンであり、151番目のポケモンはミュウである。制約上仕方ないが。
ただし、ミュウを狙う際にけつばんが現れることもあるため、この二体は遠い存在ではないのかもしれない。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(all(a));
  rep(i,n-1){
    if(a[i+1]-a[i] != 1){
      cout << a[i]+1 << endl;
      return 0;
    }
  }
}