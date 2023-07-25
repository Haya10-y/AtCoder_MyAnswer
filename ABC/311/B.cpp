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

//問題文：https://atcoder.jp/contests/abc311/tasks/abc311_b

/*
解答方針
ランレングス圧縮 (RLE) と同様のアルゴリズムで解くことができる。
最終的な答えmaxstreakと現在の連続日数streakを用意し、全員の予定が合うならstreak++、そうでなければstreak = 0とする。
毎回maxstreakを更新し、すべて走査したあとのmaxstreakが答えになる。
*/

int main(){
  int n,d;
  cin >> n >> d;
  vector<string> s(n);
  rep(i,n){
    cin >> s[i];
  }
  int maxstreak = 0;
  int streak = 0;
  rep(i,d){
    bool isOK = true;
    rep(j,n){
      if(s[j][i] == 'x')isOK = false;
    }
    if(isOK){
      streak++;
    }else{
      streak = 0;
    }
    maxstreak = max(streak,maxstreak);
  }
  cout << maxstreak << endl;
}