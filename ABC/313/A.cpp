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

//問題文：https://atcoder.jp/contests/abc313/tasks/abc313_a
/*
解答方針
人2から人Nまでのうち、最強を決めた上で人1と戦わせます。
人1が上げるべきプログラミング力は、最強-人1+1と0のうち大きい方です。
なお、人が1人しかいなかった場合は人1が最強であることが確定します。
*/

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i,n){
    cin >> p[i];
  }
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  cout << max(0,*max_element(p.begin()+1,p.end())-p[0]+1) << endl;
}