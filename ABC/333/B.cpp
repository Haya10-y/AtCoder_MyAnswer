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

long long pow_ll(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

/*
解答方針
五角形の対角線の数と辺の数の和はせいぜい10個である．
そのため，コード内に辺または対角線とその長さを埋め込んでしまっても問題ない．
入力において頂点の順番が逆である場合も考えられるため，入力はソートし，埋め込むものは辞書順最小にしよう．
*/

int main(){
  string s,t;
  cin >> s >> t;
  sort(all(s));
  sort(all(t));
  map<string, int> mp;
  mp["AB"] = 1;
  mp["BC"] = 1;
  mp["CD"] = 1;
  mp["DE"] = 1;
  mp["AE"] = 1;
  mp["AC"] = 2;
  mp["BD"] = 2;
  mp["CE"] = 2;
  mp["AD"] = 2;
  mp["BE"] = 2;
  if(mp[s] == mp[t]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}