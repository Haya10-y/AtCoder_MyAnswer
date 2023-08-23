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

//問題文：https://atcoder.jp/contests/abc314/tasks/abc314_b
/*
解答方針
やや実装の重い問題です。がんばりましょう。
入力からすこし特殊で、賭けた個数のあとに賭けた目を入力するのをN回繰り返す形になります。
二次元配列を用意し、要素を空の配列で埋めて適宜要素をpushしていきましょう。
ルーレットの判定自体は難しくなく、Xと賭けた目が同じであるかif文で判定するだけです。
当選した場合は賭けた個数に対して振り分けます。ここでは二次元配列をつかっています。
振り分けたあと、賭けた個数の順に配列を走査し、人がいたら同じ個数をかけている人がいないか確認したうえで答えを出力します。
このとき、二次元配列の要素数およびループ回数は37より少し大きいと安全です。
もちろん37でもよいのですが、気をつけないと配列外参照などの抜け漏れが発生してWAになる可能性があります。
*/

int main(){
	int n;
    cin >> n;
    vector<vector<int>> a(n);
    rep(i,n){
    	int c;
        cin >> c;
    	vector<int> tmp(c);
        rep(j,c){
        	cin >> tmp[j];
        }
        a[i] = tmp;
    }
    int x;
    cin >> x;
    vector<vector<int>> ans(40);
    rep(i,n){
    	for(auto j: a[i]){
        	if(x == j){
            	ans[sz(a[i])].push_back(i+1);
            }
        }
    }
    rep(i,40){
    	if(sz(ans[i])!=0){
        	cout << sz(ans[i]) << endl;
        	for(auto j: ans[i]){
            	cout << j << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}