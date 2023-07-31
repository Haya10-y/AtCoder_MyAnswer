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
#define mint modint998244353;
 
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc299/tasks/abc299_b
/*
解答方針
まず、色Tのカードが出されているか判定します。1枚でも出されたらその時点で勝者が決定することが確定します。
色Tのカードが出されるたびに値の大小判定を行い、プレイヤー番号と値を更新していきます。
最後に残ったプレイヤーが勝者となります。
色Tのカードが1枚も出なかった場合は、プレイヤー1の出したカードと同じ色について、もう一度同様に判定を行います。
この判定において、必ず勝者が決定します。
*/

int main(){
  int n,t;
  cin >> n >> t;
  vector<int> c(n),r(n);
  rep(i,n){
    cin >> c[i];
  }
  rep(i,n){
    cin >> r[i];
  }
  int p1 = c[0];
  int ans = -1;
  int val = 0;
  rep(i,n){
    if(c[i] == t){
      if(val < r[i]){
        ans = i;
        val = r[i];
      }
    }
  }
  if(ans == -1){
    rep(i,n){
      if(c[i] == p1){
        if(val < r[i]){
          ans = i;
          val = r[i];
        }
      }
    }
  }
  cout << ans+1 << endl;
}