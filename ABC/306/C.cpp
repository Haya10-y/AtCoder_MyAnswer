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

//問題文：https://atcoder.jp/contests/abc306/tasks/abc306_c
/*
実装方針
何も考えず、最初に数字が出てきたら記録、もう一度出てきたらそのindexを記録しましょう。
あとは数字とindexのペアをつくり、indexの昇順にソートしましょう。
最後に順番にペア中の数字を出力していけば正解することができます。
なお、まとめてindexを記録せずとも2回目に数字が出てきた時点でその数字を出力しても問題ありません。
むしろこちらのほうが速いです（ソート分がないため）。
*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n*3);
  rep(i,n*3){
    cin >> a[i];
    a[i]--;
  }
  set<int> exist;
  vector<pair<int,int>> middle(n,make_pair(-1,-1));
  rep(i,n*3){
    if(exist.count(a[i]) && middle[a[i]] == make_pair(-1,-1)){
      middle[a[i]] = make_pair(i+1, a[i]+1);
    }else if(!exist.count(a[i])){
      exist.insert(a[i]);
    }
  }
  sort(all(middle));
  rep(i,n){
    cout << middle[i].second << " ";
  }
  cout << endl;
}