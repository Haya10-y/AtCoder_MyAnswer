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

//問題文：https://atcoder.jp/contests/abc301/tasks/abc301_c
/*
解答方針
@はatcoderのいずれかに置き換えられます。つまり、それ以外には置き換えられません。
すべての文字種において、SとTについてカウントを行います。
atcoder以外の文字数は等しいことが絶対条件であるため、そうでない時点で負けが確定します。
文字種がatcoderのうちのどれかであった場合、カウントを比較して小さいほうから差分だけ@のカウントを減らします。
これを繰り返し、最後に両者とも@のカウントが0以上であれば勝ちです。
*/

int main(){
  string s,t;
  cin >> s >> t;
  int scount = 0;
  int tcount = 0;
  map<char,int> mp_s;
  map<char,int> mp_t;
  rep(i,sz(s)){
    if(s[i] == '@'){
      scount++;
    }else{
      mp_s[s[i]]++;
    }
  }
  rep(i,sz(t)){
    if(t[i] == '@'){
      tcount++;
    }else{
      mp_t[t[i]]++;
    }
  }
  int diff_s = 0;
  int diff_t = 0;
  int atmin = min(scount, tcount);
  vector<char> repl = {'a','t','c','o','d','e','r'};
  rep(i,26){
    char c = 'a'+i;
    //cout << c << endl;
    bool flag = false;
    for(auto j: repl){
      if(j == c){
        //cout << c << endl;
        flag = true;
        break;
      }
    }
    if(flag){
      if(mp_s[c] < mp_t[c]){
        diff_s += mp_t[c] - mp_s[c];
      }else{
        diff_t += mp_s[c] - mp_t[c];
      }
    }else{
      if(mp_s[c] != mp_t[c]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  //cout << "aaa" << endl;
  if(diff_s <= scount && diff_t <= tcount){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}