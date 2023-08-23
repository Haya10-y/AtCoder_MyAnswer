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

//問題文：https://atcoder.jp/contests/abc314/tasks/abc314_d
/*
解答方針
この解法ではvector<bool>のコピーが高速であるといった言語仕様を利用しています。ご了承ください。
まず、初期状態を考えます。各文字につき、大文字であるか小文字であるかということをフラグでとっておきましょう。
操作1のときは1要素を変更します。ここは特に考えず、ふつうに変更したうえで大文字小文字を判別しましょう。
操作2・3のときが問題で、直接文字列をいじっていると間に合いません。
そこで、これらの操作が行われたあとの状態を考えます。
操作2が行われたあとはすべて小文字であり、操作3が行われたあとはすべて大文字です。
本解答ではすべてtrueのvector<bool>とすべてfalseのvector<bool>を用意しておき、操作2では後者、操作3では前者のvector<bool>を
大文字小文字の判定をするために使うvector<bool>に直接代入します。
あとはこの流れを繰り返し、最終的に文字種と大文字小文字の判定をして操作後の文字列を出力します。
*/

int main(){
	int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<bool> iscapital(n,false);
    vector<bool> alllarge(n,true);
    vector<bool> allsmall(n,false);
    rep(i,n){
    	if(isupper(s[i])){
        	iscapital[i] = true;
        }
    }
    rep(i,q){
    	int t,x;
        char c;
    	cin >> t >> x >> c;
        x--;
        if(t == 1){
        	s[x] = c;
            if(isupper(c)){
            	iscapital[x] = true;
            }else{
            	iscapital[x] = false;
            }
        }else if(t == 2){
        	iscapital = allsmall;
        }else{
        	iscapital = alllarge;
        }
    }
    rep(i,n){
    	if(iscapital[i]){
        	cout << (char)toupper(s[i]);
        }else{
        	cout << (char)tolower(s[i]);
        }
    }
    cout << endl;
}