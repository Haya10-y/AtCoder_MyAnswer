#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//問題文：https://atcoder.jp/contests/abc215/tasks/abc215_a
/*
解答方針
かなり簡単な問題です。
文字列を入力し、"Hello,World!"と一致するか判定しましょう。
*/

int main(){
  string s;
  cin >> s;
  if(s == "Hello,World!"){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
}