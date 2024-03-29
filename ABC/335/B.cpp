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
#define pii pair<int,int>
#define pll pair<ll,ll>
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
三重ループを回し，合計がNより大きくなったらbreakしよう．
i,j,kの順に出力すれば自然と辞書順になる．
なお，N = 21のとき解の個数が2024個となる．
*/

int main(){
  int n;
  cin >> n;
  //int cnt = 0;
  rep(i,n+1){
    rep(j,n+1){
      if(i+j > n)break;
      rep(k,n+1){
        if(i+j+k > n)break;
        cout << i << " " << j << " " << k << " " << endl;
        //cnt++;
      }
    }
  }
  //cout << cnt << endl; //n = 21のとき、解の個数が2024個になる
}