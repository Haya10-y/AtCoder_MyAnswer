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
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())
#define eps 0.00001
#define PI 3.14159265358979323846264338
#include <atcoder/all>
using namespace atcoder;
const int mod1 = 998244353;
const int mod2 = 1000000007;
#define mint modint998244353
#define mint2 modint1000000007
//QCFium法
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
void fast(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}
 
#define endl "\n" //flushのとき外す

//問題文：https://atcoder.jp/contests/abc281/tasks/abc281_e
/*
解答方針
典型的な、multisetを2個使う問題。
まず、上位K個と下位のそれ以外のmultisetで分ける。
最初に要素をM個入れ、K個になるまで下位に移す。このとき、絶対に上位に入らないダミーデータを入れておくと楽。
上位のものの合計を求めておき、最初の答えとする。
次以降はA_(i-1)をmultiset中から探して消し、A_(i+M-1)をmultiset中に入れ、上位がK個になるようバランスをとる。
1操作にかかる時間はO(logN)あたりであるため、十分間に合う。
要素を消した時に上位であれば合計からその分引き、要素を入れた時に上位に入ったらその分を合計に足すこと。
合計の計算量はO(NlogN)程度になる。
*/

int main(){
  fast();
  int n,m,k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  multiset<ll> leastk;
  multiset<ll> rest;
  rest.insert((ll)1e17); //絶対にleastkに入らないダミーデータ
  //まずm個入れる
  ll ans = 0;
  rep(i,m){
    leastk.insert(a[i]);
    ans+= a[i];
  }
  //k個になるまで減らす
  while(sz(leastk) > k){
    ll large = *prev(leastk.end());
    leastk.erase(prev(leastk.end()));
    rest.insert(large);
    ans -= large;
  }
  cout << ans << " ";
  //i = 2以降について考える
  rep(i,n-m){ //1 to n-m (0 ended)
    ll erased = a[i];
    ll inserted = a[i+m];
    if(leastk.count(erased)){
      leastk.erase(leastk.find(erased));
      leastk.insert(inserted);
      ans -= erased;
      ans += inserted;
    }else{
      rest.erase(rest.find(erased));
      rest.insert(inserted);
    }
    //でかかったら交換、ここでrestの要素を1以上にしているのがいきてくる
    if(*prev(leastk.end()) > *rest.begin()){
      ll toleast = *rest.begin();
      ll torest = *prev(leastk.end());
      rest.erase(rest.begin());
      leastk.erase(prev(leastk.end()));
      ll diff = toleast-torest;
      ans += diff;
      rest.insert(torest);
      leastk.insert(toleast);
    }
    cout << ans << " ";
  }
  cout << endl;
}