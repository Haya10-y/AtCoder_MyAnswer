#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep_s(i,s,n) for(int i = s; i < n; i++)
#define rep_r(i,n) for(int i = n-1; i >= 0; i--)
#define rep_rs(i,s,e) for(int i = s-1; i >= e; i--)
#define rep_b(bit,n) for (int bit = 0; bit < (1<<n); bit++)
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

/*
解答方針
イベントソートを用いて解く。
時刻・イベント番号・数値を要素としたsetを用いてpriority_queueっぽく解く。
イベント番号は0をそうめんの取得、1を列への復帰として実装している。
数値はイベント番号が0のときの流れてくるそうめんの番号、1のとき戻ってくる人の番号としている。
なお、列への復帰を優先すべく、イベント番号には十分大きい定数を足している（あとで引く）。
これにより、時刻が同じとき戻ってくる処理を先に行うことができる。
あとは待ち列をsetで表し、イベントごとに入ったり抜けたりしたうえでそうめんの取得を進めていけばよい。
*/

int main(){
  fast();
  int n,m;
  cin >> n >> m;
  vector<ll> t(m),w(m),s(m);
  rep(i,m){
    cin >> t[i] >> w[i] >> s[i];
  }
  set<pair<ll,pair<ll,int>>> st; //{time, {num, event}}, event = 0のときget、event = 1のときjoin
  //event = 0のときnum = イベント番号, event = 1のときnum = 戻ってくる人の番号
  set<int> que; //待ち列をsetで表す
  rep(i,n){
    que.insert(i);
  }
  vector<ll> somen(n,0);
  ll adjust = 1e12;
  //イベントソートのためにまず全イベントを入れる
  rep(i,m){
    st.insert(make_pair(t[i], make_pair(adjust+i, 0)));
  }
  int event, getter;
  ll tim, num;
  int cnt = 0;
  while(!st.empty()){
    /*cnt++;
    if(cnt >= 500){
      return 0;
    }
    cout << sz(st) << endl;*/
    auto p = *st.begin();
    st.erase(st.begin());
    tim = p.first;
    num = p.second.first;
    event = p.second.second;
    if(event == 0){
      num -= adjust;
      if(!que.empty()){
        getter = *que.begin();
        que.erase(que.begin());
        somen[getter] += w[num];
        st.insert(make_pair(tim+s[num], make_pair(getter, 1)));
      }
    }else{
      que.insert(num);
    }
  }
  rep(i,n){
    cout << somen[i] << endl;
  }
}