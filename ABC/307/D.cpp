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

//問題文：https://atcoder.jp/contests/abc307/tasks/abc307_d
/*
解答方針
かっこで囲われていない文字を出力する問題。
どこまでかっこで囲われているか、ということについては色々なアルゴリズムが考えられる。
例えば、ネストの深さに対応したindexをもった配列を用意し、かっこが閉じられた際に区間を保存するようなアルゴリズムを組む。
あとはABC256Dと同様に、区間を結合していけばよい。
ABC256Dに関してはこちらを参考にしてほしい。
https://atcoder.jp/contests/abc256/tasks/abc256_d
結合し終えた最終区間をもとに、各文字にフラグを立て、フラグの立っていないものを最後に出力すればよい。
なお、この処理は最悪でもO(NlogN)程度で終わる（普通はO(N)、区間が多すぎる場合はO(NlogN)）。
*/

int main(){
  fast();
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> deleted(n, false);
  set<pair<int,int>> interval;
  int depth = 0;
  vector<int> nests(n,-1);
  rep(i,n){
    if(s[i] == '('){
      nests[depth] = i;
      depth++;
    }else if(s[i] == ')' && depth > 0){
      depth--;
      if(nests[depth] != -1){
        interval.insert(make_pair(nests[depth], i));
        nests[depth] = -1;
      }
    }
    
  }
  int first = -1;
  int second = -1;
  vector<pair<int,int>> finalinterval;
  for(auto i: interval){
    //cout << i.first << " " << i.second << endl;
    if(first == -1){
      first = i.first;
      second = i.second;
    }else if(second < i.first){
      finalinterval.push_back(make_pair(first, second));
      first = i.first;
      second = i.second;
    }else{
      first = min(i.first, first);
      second = max(i.second, second);
    }
  }
  if(first != -1)finalinterval.push_back(make_pair(first, second));
  for(auto i: finalinterval){
    //cout << i.first << " " << i.second << endl;
    rep_s(j,i.first, i.second+1){
      deleted[j] = true;
    }
  }
  rep(i,n){
    if(!deleted[i]){
      cout << s[i];
    }
  }
  cout << endl;
}