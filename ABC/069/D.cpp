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
連結について考えた時、各色について一筆書きで書けるルートを考えるのが楽である。
すべてのマスを一筆書きで通るためには、へび状にたどるのが最も楽である。
そのため、へび状にマスを一色ずつ埋めていくのが楽な解法になる。
*/

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<vector<int>> field(h,vector<int>(w,-1));
  int idx = 0;
  //へび状に埋めていく
  rep(i,h){
    if(i%2==0){
      rep(j,w){
        field[i][j] = idx+1;
        a[idx]--;
        if(a[idx] == 0){
          idx++;
        }
      }
    }else{
      rep_r(j,w){
        field[i][j] = idx+1;
        a[idx]--;
        if(a[idx] == 0){
          idx++;
        }
      }
    }
  }
  rep(i,h){
    rep(j,w){
      cout << field[i][j] << " ";
    }
    cout << endl;
  }
}