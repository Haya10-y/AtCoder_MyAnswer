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

//問題文：https://atcoder.jp/contests/abc278/tasks/abc278_d
/*
解答方針
形式1のクエリをいかに高速に処理するかが大事です。
出力すべきものはA_i_qであるため、和などを考慮する必要はありません。
ここで、形式1のクエリとは、Aの全要素をx_qであることに注目します。
ただ、全要素をx_qにしていては当然間に合わないため、ここでフラグを用いて値を切り替えたあとかどうか考えます。
形式1のクエリの直後はA_iの値は自明であるため、形式2および形式3のクエリを処理したときにはじめて値を切り替えればよいです。
値を切り替えたかどうかをフラグで管理し、それによって処理を変えます。
形式1のときにフラグをすべてリセットしますが、ここであらかじめフラグがすべて立っていない配列を用意して代入すると少し速いです。
なお、どちらかというとフラグはmapで処理したほうが速いかもしれません。
*/

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<bool> emp(n,false);
  vector<bool> flag(n,true);
  ll uni;
  ll q;
  cin >> q;
  rep(i,q){
    ll query;
    cin >> query;
    if(query == 1){
      ll x;
      cin >> x;
      uni = x;
      flag = emp;
    }else if(query == 2){
      ll i,x;
      cin >> i >> x;
      i--;
      if(!flag[i]){
        a[i] = uni;
        flag[i] = true;
      }
      a[i] += x;
    }else{
      ll i;
      cin >> i;
      i--;
      if(!flag[i]){
        a[i] = uni;
        flag[i] = true;
      }
      cout << a[i] << endl;
    }
  }
}