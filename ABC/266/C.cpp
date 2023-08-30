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

//問題文：https://atcoder.jp/contests/abc266/tasks/abc266_c
/*
解答方針
この問題には様々な解答方法がありますが、今回は高校数学だけでわかるような解法にします。
1つの角のうち内側と外側で小さい方をとったうえで、すべての角の角度の和が360度になるかどうかを判定します。
こうすることで、凸でない四角形については角度の和が360度を下回ります。
4つの点の座標がわかっているため、ここから各辺の長さもわかります。
辺の長さがわかっていれば、余弦定理により角度を求めていくことができます。
これですべての角の角度を求めることができたため、あとはそれを足して360度になるかどうか判定しましょう。
ただし、誤差が発生する可能性があるため、結果に影響を与えないある程度小さい値を猶予としてもって判定しましょう。
*/

ll distpow(ll px, ll py, ll qx, ll qy){
  return (px-qx)*(px-qx)+(py-qy)*(py-qy);
}
int main(){
  ll ax,ay,bx,by,cx,cy,dx,dy;
  cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
  double cosa,cosb,cosc,cosd;
  ll ab = distpow(ax,ay,bx,by);
  ll ac = distpow(ax,ay,cx,cy);
  ll ad = distpow(ax,ay,dx,dy);
  ll bc = distpow(bx,by,cx,cy);
  ll bd = distpow(bx,by,dx,dy);
  ll cd = distpow(cx,cy,dx,dy);
  cosa = (ad+ab-bd)/(2*sqrt(ab)*sqrt(ad));
  cosb = (bc+ab-ac)/(2*sqrt(bc)*sqrt(ab));
  cosc = (bc+cd-bd)/(2*sqrt(bc)*sqrt(cd));
  cosd = (cd+ad-ac)/(2*sqrt(cd)*sqrt(ad));
  double radsum = acos(cosa)+acos(cosb)+acos(cosc)+acos(cosd);
  if(PI*2-eps <= radsum && radsum <= PI*2+eps){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}