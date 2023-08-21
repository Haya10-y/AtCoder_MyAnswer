#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define debug_st(x,y) cerr << x << " " << y << " "
#define debug_p(p) cerr << p.first << " " << p.second << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;

//問題文：https://atcoder.jp/contests/abc276/tasks/abc276_a
/*
解答方針
一番右に現れる文字'a'が左から何番目の文字であるかという問題です。
もちろん左から走査することも可能ですが、もっと簡単な方法があります。
右から走査していき、ひとつ'a'が見つかればそれが一番右の'a'であることは確定しているため、
この位置を出力すればよいです。
'a'がない場合に-1を出力することに気をつけましょう。
*/

int main(){
  string s;
  cin >> s;
  ll idx = -1;
  rep_r(i,sz(s)){
    if(s[i] == 'a'){
      idx = i+1;
      break;
    }
  }
  cout << idx << endl;
}