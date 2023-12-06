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
少し難しく、考察の必要がある。
L <= X <= Rであり、Aの各要素との差が0に限りなく近くなるようなXを探したい。
まず差が0になることについて考えると、当然X_i = A_iとなる。よって答えはA_iになる。
ただし、L <= A_i <= Rにならないことも考えられるので、ならなかった場合は
L - A_i間の差とR - A_i間の差のうちどちらが小さいかで考えればよい。前者が小さければ答えはL、後者なら答えはRになる。
*/

int main(){
  fast();
  int n,l,r;
  cin >> n >> l >> r;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    if(l <= a[i] && a[i] <= r){
      cout << a[i] << " ";
    }else{
      if(abs(l-a[i]) <= abs(r-a[i])){
        cout << l << " ";
      }else{
        cout << r << " ";
      }
    }
  }
}