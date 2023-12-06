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
3点をとってL型をつくれるかという問題になる。
ここで、L型をつくるためには中心位置となる1点と、そこから同じ行にある1点と、同じ列にある1点をとればよいということがわかる。
この組み合わせをとるためには、行ごとにoの数をカウント、列ごとにoの数をカウントしていき、そのあと中心位置を全探索していけばよい。
全体の計算量はO(N^2)であり、これは十分間に合う。
*/

int main(){
  fast();
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  //3点取ってL型をつくる、行列ごとにカウントする…？
  vector<int> cnt_row(n,0), cnt_col(n,0);
  //rowは行ごとのカウント、colは列ごとのカウント
  rep(i,n){
    rep(j,n){
      if(s[i][j] == 'o'){
        cnt_row[j]++;
        cnt_col[i]++;
      }
    }
  }
  ll ans = 0;
  //O(N^2)が間に合うので中心地点を全探索…？
  rep(i,n){
    rep(j,n){
      if(s[i][j] == 'o'){
        ans += (cnt_row[j]-1)*(cnt_col[i]-1);
      }
    }
  }
  cout << ans << endl;
}