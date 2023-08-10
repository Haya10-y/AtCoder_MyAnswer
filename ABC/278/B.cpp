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

//問題文：https://atcoder.jp/contests/abc278/tasks/abc278_b
/*
解答方針
以下のように考えるとわかりやすいかもしれません。
現在時刻がAB:CDであり、ここから時間が進む。
時刻がXY:UVのとき、初めてXU:YVとなる時刻を求めよ。

これはAB:CDから時間を進めていき、1分ごとに条件を満たすか確認していけばよいです。
見間違えやすい時刻はどこかにあるので、初めて出てきたものを出力しましょう。
*/

int main(){
  ll h,m;
  cin >> h >> m;
  while(true){
    rep_s(i,h,24){
      rep_s(j,m,60){
        ll a,b,c,d;
        a = i/10;
        b = i%10;
        c = j/10;
        d = j%10;
        ll ac,bd;
        ac = a*10+c;
        bd = b*10+d;
        if((ac >= 0 && ac <= 23) && (bd >= 0 && bd <= 59)){
          cout << a << b << " " << c << d;
          return 0;
        }
      }
      m = 0;
    }
    h = 0;
  }
  
}