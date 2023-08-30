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
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

//問題文：https://atcoder.jp/contests/abc261/tasks/abc261_c
/*
解答方針
同じ名前のものがあったら、(個数-1)を追加する問題です。
名前とその個数を対応させるのは連想配列の得意分野です。
C++ならmapを使い、名前と個数を記録したうえで文字列を加工していきましょう。
なお、C++この問題では整列されているmapではなく整列されていないunordered_mapをつかうこともできます。こちらのほうが速いです。
*/

int main(){
  ll n;
  cin >> n;
  map<string,ll> mp;
  string ans = "";
  ll num = 0;
  rep(i,n){
    ans = "";
    string s;
    cin >> s;
    num = mp[s];
    mp[s]++;
    if(num == 0){
      ans = s;
    }else{
      ans = s+"("+to_string(num)+")";
    }
    cout << ans << endl;
  }
}