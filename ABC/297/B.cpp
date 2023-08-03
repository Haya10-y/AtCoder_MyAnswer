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

//問題文：https://atcoder.jp/contests/abc297/tasks/abc297_b
/*
解答方針
問題文通りに実装し、盤面が条件を満たすか確認しましょう。
B,K,Rがどの位置にあるか記録し、位置関係を見ることで判定することができます。
*/
int main(){
  string s;
  cin >> s;
  vector<int> bidx,ridx;
  int kidx;
  rep(i,sz(s)){
    if(s[i] == 'B'){
      bidx.push_back(i);
    }
    if(s[i] == 'K'){
      kidx = i;
    }
    if(s[i] == 'R'){
      ridx.push_back(i);
    }
  }
  if(bidx[0]%2 == bidx[1]%2){
    cout << "No" << endl;
    return 0;
  }
  if(ridx[0] < kidx && kidx < ridx[1]){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}