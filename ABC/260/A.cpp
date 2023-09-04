#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug_one(x) cerr << x << endl
#define debug_space(x) cerr << x << " "
#define debug_two(x,y) cerr << x << " " << y << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

//問題文：https://atcoder.jp/contests/abc260/tasks/abc260_a
/*
解答方針
この問題にはいろいろな解答があります。
たとえば、文字種ごとにカウントし、カウントが1のものがあればそれを出力、なければ-1を出力という解答や、
1文字目と2文字目・3文字目がそれぞれ違えば1文字目を出力、
2文字目と1文字目・3文字目がそれぞれ違えば2文字目を出力…といった解答があります。
いろいろな解答方法があるので好きな方法で解いてみましょう。
*/

int main(){
  string s;
  cin >> s;
  map<char,ll> mp;
  mp[s[0]]++;
  mp[s[1]]++;
  mp[s[2]]++;
  vector<pair<char,ll>> v(all(mp));
  rep(i,sz(v)){
    if(v[i].second == 1){
      cout << v[i].first << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  
}