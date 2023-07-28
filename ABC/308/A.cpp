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

//問題文：https://atcoder.jp/contests/abc308/tasks/abc308_a
/*
実装方針
問題文通りに条件を判定しましょう。
一度に複数の条件を判定するのが難しければ、フラグを3つもって上から順番にひとつずつ処理していっても問題ありません。
すべての問題に共通していえることですが、条件を満たさないとわかった瞬間に"No"を出力してプログラムを終了し、
最後まで処理が終わった（条件を達成した）ときは"Yes"を出力するようにすると楽です。覚えておきましょう。
*/

int main(){
  int n = 8;
  vector<int> s(n);
  rep(i,n){
    cin >> s[i];
  }
  int prev = -1;
  rep(i,n){
    if(s[i]%25 == 0 && 100 <= s[i] && s[i] <= 675 && prev <= s[i]){
      prev = s[i];
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}