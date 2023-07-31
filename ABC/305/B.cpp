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

//問題文：https://atcoder.jp/contests/abc305/tasks/abc305_b
/*
解答方針
距離はあらかじめ決まっているため、プログラム中に埋め込んでください。
ここで、C++ではchar型の値はASCIIコードとの対応付けができるため、'A' = 65を引くことで距離配列のindexに直すことができます。
あとは始点と終点を決め、その間の数値を足していけばよいです。
なお、累積和を用いてもよいです。この場合、配列の中身は{0,3,4,8,9,14,23}となります。
また、この値は点A-Gの座標に等しいです。
*/

int main(){
  char p,q;
  cin >> p >> q;
  vector<int> len = {3,1,4,1,5,9};
  int start = min(p-'A',q-'A');
  int dst = max(p-'A',q-'A');
  int ans = 0;
  for(int i = start; i < dst; i++){
    ans += len[i];
  }
  cout << ans << endl;
}