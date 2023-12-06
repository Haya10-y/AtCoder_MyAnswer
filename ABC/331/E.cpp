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
まず、主菜を決めたあとのことを考える。
このとき、当然だが副菜はとれるものの中で価値が最大のものをとることになる。
主菜と副菜については、価値の順番にソートしておく。
主菜を全探索し、とれない副菜についてはsetなどで管理したうえで上から順番に試していこう。
ひとつでも副菜がとれたらその主菜についてはそれ以上試す必要はない。
このとき試す副菜はたかだかN+L個におさまる。
あとはこの価値の最大を出力してやればよい。
*/

int main(){
  fast();
  int n,m,l;
  cin >> n >> m >> l;
  vector<pair<ll,int>> a(n),b(m);
  ll atmp,btmp;
  rep(i,n){
    cin >> atmp;
    a[i] = make_pair(atmp, i);
  }
  rep(j,m){
    cin >> btmp;
    b[j] = make_pair(btmp, j);
  }
  sort(all(a), greater());
  sort(all(b), greater());
  vector<int> c(l),d(l);
  rep(i,l){
    cin >> c[i] >> d[i];
    c[i]--;d[i]--;
  }
  vector<set<int>> banned(n);
  rep(i,l){
    banned[c[i]].insert(d[i]);
  }
  ll ans = 0;
  rep(i,n){
    rep(j,m){
      if(banned[a[i].second].count(b[j].second)){
        continue;
      }
      ans = max(ans, a[i].first+b[j].first);
      break;
    }
  }
  cout << ans << endl;
}