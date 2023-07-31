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

//問題文：https://atcoder.jp/contests/abc300/tasks/abc300_b
/*
解答方針
よく考えると、同じマップを2*2で並べることで、そのうちのH*Wマスを取り出したものが
いずれかのシフトパターンに当てはまることがわかります。
これをもとにすべてのH*Wマスを探索することで、当てはまっているシフトパターンがあるか判定することができます。
もちろん、普通にシフトを行っても構いません。この場合は、
縦シフト→W回横シフト（判定は1回ごとに行う）をH回繰り返すことで実装ができます。
*/

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w)), b(h,vector<char>(w));
  vector<vector<char>> quad(h*2, vector<char>(w*2));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }
  rep(i,h){
    rep(j,w){
      cin >> b[i][j];
    }
  }
  rep(i,h*2){
    rep(j,w*2){
      quad[i][j] = a[i%h][j%w];
    }
  }
  /*rep(i,h*2){
    rep(j,w*2){
      cout << quad[i][j];
    }
    cout << endl;
  }*/
  rep(i,h+1){
    rep(j,w+1){
      bool flag = true;
      rep(k,h){
        rep(l,w){
          //cout << i << " " << j << " " << k << " " << l << endl;
          if(quad[i+k][j+l] != b[k][l]){
            flag = false;
            break;
          }
        }
        if(!flag){
          break;
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}