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

//問題文：https://atcoder.jp/contests/abc301/tasks/abc301_b
/*
解答方針
出力例から、最後にできる数列について考えましょう。
2,5,1,2が入力としてあたえられた場合、出力は2,3,4,5,4,3,2,1,2となります。
これは2, 2+1=3から5-1=4まで, 5, 5-1=4から1+1=2まで, 1, 1+1=2から2-1=1まで（ここは出力なし）, 2を順番に出力するのと同義です。
値が増えていくか減っていくか判定した上でforループを組み、順番に出力すればよいです。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  cout << a[0] << " ";
  rep_s(i,1,n){
    int diff = a[i]-a[i-1];
    if(diff != 1){
      if(diff > 0){
        for(int j = a[i-1]+1; j < a[i]; j++){
          cout << j << " ";
        }
      }else{
        for(int j = a[i-1]-1; j > a[i]; j--){
          cout << j << " ";
        }
      }
    }
    cout << a[i] << " ";
  }
}