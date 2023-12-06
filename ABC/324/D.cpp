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
並べ替えた文字列を数字とみて考える。N <= 13より、並び替えた文字列の最大値はたかだか10^13-1となる。
Sを並び替えたときの最大値をMとおいたとき、i*i <= Mとなるiが存在し、かつi*iがSの並び替えであるかどうか見ていきたい。
ひとまずiの探索範囲としては0 <= i <= sqrt(M)になる。これは最大でも4*10^6以下であり、十分間に合う。
あとは並び替えの判定だが、ここでは桁ごとの数字をカウントする手法を用いる。
はじめにSの桁ごとの数字をカウントしておき、vectorに保存する。
次にi*iの桁ごとの数字を保存していく。ここでこのカウントがSの文字数カウントに一致したら答えのカウントを増やす。
なお、0の個数がSよりi*iのほうが小さいことに関しては気にしないものとする（i*iについては後ろに0をつけられるため）。
*/

int main(){
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<int> cnt(10,0);
  rep(i,n){
    cnt[s[i]-'0']++; //桁ごとの数字をカウント
  }
  string s_max = s;
  sort(all(s_max),greater());
  ll maxnum = stoll(s_max); //最大値、これ以上はとれない
  
  int ans = 0;
  
  //i <= sqrt(10^13) <= 4*10^6.
  for(ll i = 0; i*i <= maxnum; i++){
    vector<int> cnt_tmp(10,0);
    ll quad = i*i;
    if(quad == 0){
      cnt_tmp[0]++; //0は平方数
    }else{
      while(quad != 0){
        //桁ごとの数字をカウント
        cnt_tmp[quad%10]++;
        quad /= 10;
      }
    }
    rep(i,10){
      if(i == 0){
        if(cnt_tmp[i] > cnt[i]){
          break;
        }
      }else{
        if(cnt_tmp[i] != cnt[i]){
          break;
        }
      }
      //最後までできたら
      if(i == 9){
        ans++;
      }
    }
  }
  cout << ans << endl;
}