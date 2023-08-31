#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < n; i++)
#define rep_s(i,s,n) for(ll i = s; i < n; i++)
#define rep_r(i,n) for(ll i = n-1; i >= 0; i--)
#define rep_b(bit,n) for (ll bit = 0; bit < (1<<n); bit++)
#define enum_bit() if(bit & (1<<i))
#define debug(x) cerr << x << endl
#define debug_s(x) cerr << x << " "
#define debug_t(x,y) cerr << x << " " << y << endl
#define all(a) a.begin(),a.end()
#define sz(v) ((ll)v.size())

//問題文：https://atcoder.jp/contests/abc260/tasks/abc260_b
/*
解答方針
まず前提として、人の情報を{点数, 受験番号}のペアでとります。
また、合格になった人の番号を記録する必要があるため、set<int>やvector<bool>などでとっておきましょう。
まず、数学・英語・数学と英語の点数が高い方を先頭にしてソートします。ただし、同じ点数なら番号の小さい順にします。
そのあと、まず数学の点数が高いX人を合格とします。
次に英語の点数が高いY人を合格とします。ただし、すでに合格している人はカウントしません。
最後に数学と英語の合計点について同じことを行います。
これらを行ったあとに、合格者を番号の小さい順から出力しましょう。
*/

bool comp(pair<ll, ll>& left, pair<ll, ll>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main(){
  ll n,x,y,z;
  cin >> n >> x >> y >> z;
  vector<pair<ll,ll>> a(n),b(n),c(n);
  rep(i,n){
    cin >> a[i].first;
    a[i].second = i+1;
  }
  rep(i,n){
    cin >> b[i].first;
    b[i].second = i+1;
    c[i].second = i+1;
    c[i].first = a[i].first + b[i].first;
  }
  sort(all(a),comp);
  sort(all(b),comp);
  sort(all(c),comp);
  /*rep(i,n){
    debug_t(a[i].first,a[i].second);
  }*/
  set<ll> pass;
  rep(i,x){
    //debug_t("A Insert:",a[i].second);
    pass.insert(a[i].second);
  }
  rep(i,y){
    if(pass.count(b[i].second)){
      y++;
      continue;
    }else{
      //debug_t("B Insert:",b[i].second);
      pass.insert(b[i].second);
    }
  }
  rep(i,z){
    if(pass.count(c[i].second)){
      z++;
      continue;
    }else{
      //debug_t("C Insert:",c[i].second);
      pass.insert(c[i].second);
    }
  }
  vector<ll> ans(all(pass));
  rep(i,ans.size()){
    cout << ans[i] << endl;
  }
}