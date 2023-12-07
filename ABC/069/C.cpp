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
隣り合った項の積を4の倍数にするためには、片方が4の倍数であるか、両方が2の倍数であることが条件になる。
便宜上、4の倍数でなく2の倍数であるものを2の倍数とよび、2で割り切れない数を1の倍数とよぶ。
まずは1の倍数の隣に4の倍数を添えることを考える。
ここで、1の倍数の個数が4の倍数の個数より大きくなってしまうと一部を除き条件が成り立たなくなってしまう。
その一部が1の倍数の個数 - 4の倍数の個数 = 1の場合だが、この場合は2の倍数がない場合のみ条件が成り立つ。
4の倍数の個数のほうが大きい場合は後ろに2の倍数をくっつければよいだけであり、これは必ず条件を満たす。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int mul1 = 0;
  int mul2 = 0;
  int mul4 = 0;
  rep(i,n){
    cin >> a[i];
    if(a[i] %2 != 0){
      mul1++;
    }else if(a[i] %4 == 0){
      mul4++;
    }else{
      mul2++;
    }
  }
  //cout << mul1 << " " << mul2 << " " << mul4 << endl;
  if(mul1-mul4 > 1){
    cout << "No" << endl;
  }else if(mul1-mul4 == 1){
    if(mul2 == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    cout << "Yes" << endl;
  }
}