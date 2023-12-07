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
最初にドから始まる鍵盤を2つ並べてしまおう。こうすることで、シからドにまたぐ処理を考えなくてよくなる。
音階は12音でループするため、Sのうちから最初の12文字とれば十分。
あとはどの位置から始まっているか、1ループ分調べればよい。少し面倒だが頑張ろう。
*/

int main(){
  string s;
  cin >> s;
  string sub = s.substr(0,12);
  string kb = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
  if(sub == kb.substr(0,12)){
    cout << "Do" << endl;
  }else if(sub == kb.substr(2,12)){
    cout << "Re" << endl;
  }else if(sub == kb.substr(4,12)){
    cout << "Mi" << endl;
  }else if(sub == kb.substr(5,12)){
    cout << "Fa" << endl;
  }else if(sub == kb.substr(7,12)){
    cout << "So" << endl;
  }else if(sub == kb.substr(9,12)){
    cout << "La" << endl;
  }else if(sub == kb.substr(11,12)){
    cout << "Si" << endl;
  }
}