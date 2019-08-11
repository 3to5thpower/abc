#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) 
#define repi(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vin(v) rep(i,v.size()) {cin >> v[i];}
//最終奥義
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

#define pr pair<int,int>

signed main(void){
  int n,m;cin >> n >> m;
  vector<pr> ba;
  rep(i,n){
    pr t;cin >> t.second >> t.first;
    if(t.second<=m)ba.push_back(t);
    else n--;
  }
  sort(all(ba),[](pr a,pr b) -> auto {return a>b;});


  vint d(n,0);
  rep(i,n){
    int pos=i+ba[i].second;
    d[pos]+=ba[i].first;
  }

  rep(i,n)cout << d[i] << endl;

  cout << d[m] << endl;

}
