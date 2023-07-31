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

//問題文：https://atcoder.jp/contests/abc299/tasks/abc299_c
/*
解答方針
まず、棒は左右にどちらかついていればよいため、棒とダンゴがひとつでもついていればダンゴ文字列は絶対に存在します。
棒とダンゴが最低1つあるとき、あとは最長のダンゴの長さを求めればよいです。
ダンゴがある場合カウントを+1し、ない場合は0にします。また、毎回最大カウントを更新します。
答えは最大カウントです。ただし、ダンゴか棒がない場合は-1を出力します。
*/

int main(){
  fast();
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool hasstick = false;
  int streak = 0;
  int ans = -1;
  rep(i,n){
    if(s[i] == '-'){
      hasstick = true;
      if(streak >= 1){
        ans = max(streak,ans);
      }
      streak = 0;
    }else{
      streak++;
      if(i == n-1 && hasstick){
        ans = max(streak,ans);
      }
    }
  }
  cout << ans << endl;
}