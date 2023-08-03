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
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc297/tasks/abc297_d
/*
解答方針
この問題における操作は以下のふたつである。
A > Bのとき A = A - B
A < Bのとき B = B - A
当然だが制約の値が大きく、愚直にやっても間に合わない。
そこで、何回まとめて操作ができるか、ということを考える。
不等式の関係が変わらなければずっと同じ操作をしているため、
不等号が変わるところをひとつの区切りとして考えていくとよい。
不等号が変わるまでに何回操作を行うかは簡単な計算で求めることができるため、
あとはそれをA = Bになるまで繰り返し足してやればよい。
なお、この操作はユークリッドの互除法と等しく、残ったAとBは元のAとBの最大公約数となる。
*/

int main(){
  fast();
  ll a,b;
  cin >> a >> b;
  ll ans = 0;
  while(a != b){
    if(a > b){
      ll diff = a-b;
      ll cnt = (diff+b-1)/b;//ceil(diff/b)
      ans += cnt;
      a -= cnt*b;
    }else{
      ll diff = b-a;
      ll cnt = (diff+a-1)/a;
      ans += cnt;
      b -= cnt*a;
    }
  }
  cout << ans << endl;
}