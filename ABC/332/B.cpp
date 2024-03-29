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
グラスとマグカップの水をどうこうする問題．
条件が3つ与えられているため，これをコードに起こしてみよう．
グラスとマグカップの容量と現在入っている水の量をそれぞれ変数にしておき，K回シミュレーションを行おう．
マグカップからグラスに移動する水の量は，min(G-グラスに入っている水の量, マグカップに入っている水の量)で表せる．
*/

int main(){
  int k,g,m;
  cin >> k >> g >> m;
  int glass = g;
  int cup = m;
  rep(i,k){
    if(glass == g){
      glass = 0;
    }else if(cup == 0){
      cup = m;
    }else{
      int sw = min(g-glass, cup);
      glass += sw;
      cup -= sw;
    }
  }
  cout << glass << " " << cup;
}