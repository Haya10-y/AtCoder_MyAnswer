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
得票数が最多であり、かつその中で番号が最小の人をとりたい。
これは順序付き集合setを使うことで簡単に解ける。
setの中身を{-cnt,num}とすることで、得票数が最多の場合firstが最小になるため先頭に出てくる。
あとはこれを繰り返して、先頭にいる人の番号をとればよい。
なお、もちろん普通にやっても解けるが、setの中身の個数を制限することでさらに高速に解くこともできる。
*/

int main(){
  fast();
  int n,m;
  cin >> n >> m;
  set<pair<int,int>> st; //{cnt,num}とする
  vector<int> cnt(n,0);
  rep(i,min(n,3)){
    st.insert(make_pair(0,i));
  }
  int a;
  rep(i,m){
    cin >> a;
    a--;
    cnt[a]++;
    st.insert(make_pair(-cnt[a],a));
    if(sz(st) >= 3){
      st.erase(prev(st.end()));
    }
    auto p = *st.begin();
    cout << p.second + 1 << endl;
  }
}