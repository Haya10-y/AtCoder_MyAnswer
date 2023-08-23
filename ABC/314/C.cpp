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

//問題文：https://atcoder.jp/contests/abc314/tasks/abc314_c
/*
解答方針
同じ色の要素を右にひとつ巡回シフトする問題です。
まずは同じ色の要素をまとめましょう。このとき、まとめるものは要素のインデックスにしましょう。
まとめおわったらそれを右にひとつ巡回シフトします。
右にひとつ巡回シフトとはすなわち、隣り合う要素のスワップを繰り返して一番右の要素を最小手数で一番左に移すことと同じです。
すべての色について同じことを行います。
ループだけ見るとO(NM)に見えそうですが、要素の数は最大でNであるため、実際はO(N+M)になり十分間に合います。
*/

int main(){
	int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i,n){
    	cin >> c[i];
        c[i]--;
    }
    vector<vector<int>> reallocated(m);
    rep(i,n){
    	reallocated[c[i]].push_back(i);
    }
    rep(i,m){
    	int realsize = sz(reallocated[i]);
    	if(realsize >= 2){
        	for(int j = realsize-1; j >= 1; j--){
            	swap(s[reallocated[i][j]],s[reallocated[i][j-1]]);
            }
        }
    }
    cout << s << endl;
}