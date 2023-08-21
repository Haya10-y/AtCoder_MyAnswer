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

//問題文：https://atcoder.jp/contests/abc277/tasks/abc277_b
/*
解答方針
問題文をわかりやすいように置き換えましょう。
1文字目はH,D,C,Sであり、これはいわゆるトランプのスートです。
また、2~9,A,T,J,Q,Kはトランプの数字です。
1組のトランプに同じカードがあってはいけないため、それも考える必要があります。
このとき、このトランプの1組（一部あるいは全部）が正しいものであるかということを見ます。
文字が正しいかどうかはif文で判定でき、重複がないかどうかはsetで簡単に判定できます。
また、vector<string>にカードを入れていき、ひとつずつ確認する方法でももちろんよいです。
*/

int main(){
  ll n;
  cin >> n;
  set<string> st;
  rep(i,n){
    string s;
    cin >> s;
    if(s[0] != 'H' && s[0] != 'D' && s[0] != 'C' && s[0] != 'S'){
      cout << "No" << endl;
      return 0;
    }
    if((s[1] >= '2' && s[1] <= '9') || s[1] == 'A' || s[1] == 'T' || s[1] == 'J' || s[1] == 'Q' || s[1] == 'K'){
      
    }else{
      cout << "No" << endl;
      return 0;
    }
    if(st.count(s) == 0){
      st.insert(s);
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}