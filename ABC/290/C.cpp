#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(ll i = s-1; i >= e; i--)
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

//問題文：https://atcoder.jp/contests/abc290/tasks/abc290_c
/*
解答方針
a[i]の要素の種類について考えます。
ここで、別に値の小さい順からとっても問題ありません。なぜなら、そこから順序を適切に入れ替えれば
もとのAの順序から変わらなくなるからです。
また、MEXの最大値をとりたいため、同じ数を2種類以上取る必要はありません。これは無駄になり、MEXの値が小さくなるからです。
よって、a[i]の要素からありえるものを0から考え、K個までにないものがあれば途中でやめます。
K個に達したら、0~K-1が要素としてあるため、MEXはKになります。
これはおおよそO(NlogN)程度で終わるため、十分高速です。
*/

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  ll mx = -1;
  rep(i,n){
    cin >> a[i];
    mx = max(mx,a[i]);
  }
  set<ll> st;
  rep(i,n){
    st.insert(a[i]);
  }
  //vector<ll> v_st(all(st)); //mex(all)
  ll cnt = 0;
  rep(i,mx+2){
    if(st.count(i) == 0){
      cout << i << endl;
      return 0;
    }else{
      if(cnt >= k){
        cout << i << endl;
        return 0;
      }else{
        cnt++;
      }
    }
  }
}