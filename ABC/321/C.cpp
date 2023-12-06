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
321-like numberは各桁が狭義単調減少になっている。ということは、各数字はたかだか1回しか現れないことになる。
最大の321-like numberは9876543210であり、10桁である。
0-9の部分集合を全て取り出す際にはbit全探索が有効である。ありうる321-like numberをすべて作ってしまおう。
部分集合を取り出し、それらを結合した上で降順ソートすることで各桁が広義単調減少になる数を手に入れられる。
あとはこれが321-like numberであるか判定し、そうであればリストに入れていく。
最終的にリストに入ったものを昇順ソートし、そのうちのK番目のものが答えとなる。
なお、9876543210のみ32bit整数で表せないため、注意すること。
*/

int main(){
  int k;
  cin >> k;
  vector<ll> ans;
  rep_b(bit,10){
    string str = "";
    rep(i,10){
      enum_bit(){
        char c = 48+i; //"0" == 48
        str.push_back(c);
      }
    }
    if(str != "" && str != "0"){
      sort(all(str),greater());
      ans.push_back(stoll(str));
    }
  }
  sort(all(ans));
  cout << ans[k-1] << endl;
}