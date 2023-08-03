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

//問題文：https://atcoder.jp/contests/abc297/tasks/abc297_c
/*
解答方針
横に並んだTTをPCに変換する問題です。
左上から愚直に解いていきましょう。Tが横に2個並んでいたらそれらをPCに変換します。
Tがひとつしかない場合は操作しないことに注意しましょう。
*/

int main(){
  fast();
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h){
    cin >> s[i];
  }
  int ans = 0;
  rep(i,h){
    int streak = 0;
    rep(j,w){
      if(s[i][j] == 'T'){
        streak++;
      }else{
        streak = 0;
      }
      if(streak == 2){
        ans++;
        s[i][j-1] = 'P';
        s[i][j] = 'C';
        streak = 0;
      }
    }
  }
  rep(i,h){
    cout << s[i] << endl;
  }
}