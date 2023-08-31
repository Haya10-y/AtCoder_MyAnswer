#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)

//問題文：https://atcoder.jp/contests/abc259/tasks/abc259_c
/*
解答方針
タイトル通り、何回でもXXをXXXにしたとき、SをTにできるかという問題です。
ここで考えたいこととして、TにおいてXが何個繋がっていても、
SにおいてXが2個あれば再帰的にXを増やすことができるので大丈夫、ということです。
これを判定するためには、ランレングス圧縮という手法が簡単です。
簡単に言うと、どの文字がどのくらいの長さ繋がっているのか、ということです。
これを行い、ひとかたまりにおいてSの文字とTの文字が同じであるか判定したのち、
Tにおいて1文字ならSにおいて1文字のみ通り、あとはS・Tにおいて2文字以上ならSにおける文字数 <= Tにおける文字数なら通ります。
最後まで通ればYes、途中で無理だと判定されたらNoです。
*/

int main(){
  string s,t;
  cin >> s >> t;
  vector<pair<char,ll>> rle_s;
  vector<pair<char,ll>> rle_t;
  ll streak = 1;
  
  rep(i,(ll)s.size()-1){
    if(s[i] == s[i+1]){
      streak++;
    }else{
      rle_s.push_back({s[i],streak});
      streak = 1;
    }
  }
  rle_s.push_back({s[s.size()-1],streak});
  streak = 1;
  rep(i,(ll)t.size()-1){
    if(t[i] == t[i+1]){
      streak++;
    }else{
      rle_t.push_back({t[i],streak});
      streak = 1;
    }
  }
  rle_t.push_back({t[t.size()-1],streak});
  //RLE OK
  
  bool isOK = true;
  
  rep(i,(ll)rle_s.size()){
    if(rle_s[i].second >= 2){
      if(rle_s[i].first != rle_t[i].first){
        isOK = false;
        break;
      }
      if(rle_s[i].second > rle_t[i].second){
        isOK = false;
        break;
      }else{
        continue;
      }
    }else{
      //cerr << "count = 1" << endl;
      if(rle_t[i].first == rle_s[i].first && rle_t[i].second == rle_s[i].second){
        continue;
      }else{
        isOK = false;
        break;
      }
    }
  }
  if(rle_s.size() != rle_t.size()){
    isOK = false;
  }
  /*rep(i,(ll)rle_s.size()){
    cerr << rle_s[i].first << " " << rle_s[i].second << endl;
  }
  rep(i,(ll)rle_t.size()){
    cerr << rle_t[i].first << " " << rle_t[i].second << endl;
  }*/
  if(isOK){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}