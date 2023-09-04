#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//問題文：https://atcoder.jp/contests/abc215/tasks/abc215_c
/*
解答方針
|S| <= 8という制約からエスパーできるかもしれません。
できなかったとしても、「文字を並び替える」というところから想像できそうです。
この問題は順列全探索を用いて解くことができます。ありうる並びをすべて列挙するものです。
順列全探索をする前にSを昇順ソートしておくことにより、その後の順列を辞書順にとってくれるため、
これをK回繰り返せばよいです。
順列全探索においてはC++ではnext_permutationを使いましょう。
*/

int main(){
  string s;
  ll k;
  cin >> s >> k;
  ll count = 0;
  //string  s = "ABCD";

  //cout << s << '\n';
  sort(s.begin(), s.end());
  if(k == 1){
    cout << s << endl;
    return 0;
  }
  while (next_permutation(s.begin(), s.end()) && count != k){
    count++;
    if(count == k-1){
      cout << s << endl;
    }
    //cout << s << endl;
  }
  return (0);
}