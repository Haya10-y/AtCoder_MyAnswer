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

//問題文：https://atcoder.jp/contests/abc301/tasks/abc301_a
/*
解答方針
高橋くんと青木くんの勝利数を記録していきます。
勝利数が同じ場合は、最後に勝ったほうが負けとなります。
これはforループで実装することができます。
*/

int main(){
  int n;
  string s;
  cin >> n >> s;
  int t = 0;
  int a = 0;
  bool takahashi = false;//false -> aoki
  rep(i,n){
    if(s[i] == 'T'){
      t++;
      takahashi = false;
    }else{
      a++;
      takahashi = true;
    }
  }
  if(t > a){
    cout << "T" << endl;
  }else if(a > t){
    cout << "A" << endl;
  }else{
    if(takahashi){
      cout << "T" << endl;
    }else{
      cout << "A" << endl;
    }
  }
}