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
#define mod1 998244353
#define mod2 1000000007

/*
解答方針
もちろんA-Fに対してそれぞれ条件分岐をしてもよいが、もっと簡単な方法がある。
char型をキーとしたmapにカウントを記録する方法があり、これを用いると楽である。
また、（大文字char）-'A'がAを0番目としたとき何番目になるかという数字になるため、これを用いることもできる。
あらかじめ"ABCDEF"という文字列を作っておくとさらに楽になる。
*/

int main(){
  string s;
  cin >> s;
  map<char,ll> mp;
  rep(i,sz(s)){
    mp[s[i]]++;
    //cout << mp[s[i]] << endl;
  }
  string tmp = "ABCDEF";
  rep(i,sz(tmp)){
    cout << mp[tmp[i]];
    if(i < sz(tmp) - 1){
      cout << " ";
    }
  }
  cout << endl;
}