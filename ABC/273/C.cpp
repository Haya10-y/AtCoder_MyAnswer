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

//問題文：https://atcoder.jp/contests/abc273/tasks/abc273_c
/*
解答方針
以前の解法が複雑でわかりづらかったため、より簡易的にしたものを載せる。
まず、この問題ではA_iより大きいものの種類について聞かれている。
ここで、大事なのは整数の種類だけであり、その数は聞かれていない。
よってまずはsetを使って重複なしの要素の集合をとり、A_i + 1以上の数がどのくらいあるのか二分探索で見ていきたい。
なお、何種類の大きい要素があるのかは二分探索で見つけたイテレータとコンテナの最後との距離になり、vectorならdistance関数を用いて求められる。
そのため、distance関数を使うためにvectorに要素をすべて移したい。二分探索の前にやっておこう。
あとは距離をカウントしていき、最後に0から順に出力すればよい。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  set<int> st;
  rep(i,n){
    st.insert(a[i]);
  }
  vector<int> bin;
  while(!st.empty()){
    bin.push_back(*st.begin());
    st.erase(st.begin());
  }
  vector<int> cnt(n,0);
  rep(i,n){
    auto iter = lower_bound(all(bin),a[i]+1);
    int dist = distance(iter,bin.end());
    cnt[dist]++;
  }
  rep(i,n){
    cout << cnt[i] << endl;
  }
}