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

//問題文：https://atcoder.jp/contests/abc296/tasks/abc296_a
/*
解答方針
男女が交互に並んでいるということは、必然的にs[i]とs[i+1]が違うということになります。
この判定をループで行い、最後まで条件を満たしたらtrueを出力します。
例えばMFMMFMFはs[2]とs[3] (0-indexed) が同値であるためfalseが確定します。
*/

int main(){
  ll n;
  cin >> n;
  string s;
  char c;
  cin >> s;
  c = s[0];
  rep_s(i,1,n){
    if(s[i] == c){
      cout<< "No" << endl;
      return 0;
    }
    c = s[i];
  }
  cout << "Yes" << endl;
}