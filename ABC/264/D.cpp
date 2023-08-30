#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_re(i,n,e) for(ll i = n-1; i > e; i--)
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

//問題文：https://atcoder.jp/contests/abc264/tasks/abc264_d
/*
解答方針
バブルソートで並び順をatcoderにしたとき、何回swapする必要があるか考える問題。
バブルソート自体はO(N^2)だが、N = 7なので十分間に合う。
ソートの順序を決めたうえでバブルソートしてしまおう。これで十分解くことができる。
*/

int main(){
  string s;
  cin >> s;
  ll count = 0;
  rep(i,sz(s)-1){
    rep_re(j,sz(s),i){
      if(s[j] == 'a'){
      swap(s[j-1],s[j]);
      count += 1;
    }else if(s[j] == 't' && s[j-1] != 'a'){
      swap(s[j-1],s[j]);
      count += 1;
    }else if(s[j] == 'c' && s[j-1] != 'a' && s[j-1] != 't'){
      swap(s[j-1],s[j]);
      count += 1;
    }else if(s[j] == 'o' && s[j-1] != 'a' && s[j-1] != 't' && s[j-1] != 'c'){
      swap(s[j-1],s[j]);
      count += 1;
    }else if(s[j] == 'd' && (s[j-1] == 'e' || s[j-1] == 'r')){
      swap(s[j-1],s[j]);
      count += 1;
    }else if(s[j] == 'e' && s[j-1] == 'r'){
      swap(s[j-1],s[j]);
      count += 1;
    }else{
      count += 0;
    }
      cerr << s << endl;
    }
  }
  cout << count << endl;
}