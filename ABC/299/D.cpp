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
#define mint modint998244353;

//問題文：https://atcoder.jp/contests/abc299/tasks/abc299_d
/*
解答方針
0と1の境界を見つける問題です。ただし、N <= 2*10^5であり、20回までしか聞くことができないため
適当にやっても当たるはずがありません。
そこで、S_1が0、S_Nが1であることに注目します。たとえば、Sとしてありえる文字列の例は以下のとおりです。
0000001111
0000000001
0111111111
0011001101
以上のように、どこかに絶対0と1の境界があります。そこを頑張って探しましょう。
考え方は以下のようになります。
・はじめの探索区間は1~Nである。左端を1、右端をNとおく。左端と右端の真ん中について、以下の通り考える。
・0が出てきた場合、左端を現在の真ん中とする。
・1が出てきた場合、右端を現在の真ん中とする。
・真ん中を再計算し、ふたたび上のふたつについて考える。
・これを左端と右端の距離差が1になるまで行う。

これはいわゆる二分探索であり、計算量はO(logN)です。
log2(2*10^5) <= 18であることから、20回までに間に合います。
答えは探索後の左端になります。
*/

int main(){
  int n;
  cin >> n;
  int high = n;
  int low = 1;
  int mid = (high+low)/2;
  while(high - low > 1){
    cout << "? " << mid << endl;
    int ret;
    cin >> ret;
    if(ret == 0){
      low = mid;
      mid = (high+low)/2;
    }else{
      high = mid;
      mid = (high+low)/2;
    }
  }
  cout << "! " << low << endl;
  return 0;
}