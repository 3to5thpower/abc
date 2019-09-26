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

#define pint pair<int,int>
//最終奥義
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

signed main(void){
  int n;cin >> n;
  vector<pair<int,int>> a(n);
  rep(i,n){
    cin >> a[i].first;
    a[i].second=i;
  }
  vint ans(n,0);

  sort(all(a),[](pint x, pint y) -> int {return x.first > y.first;});
  
  int e=a[0].second;
  int m = a[0].first;
  rep(i,n){
    if(i==e)continue;
    else ans[i]=m;
  }
  ans[e]=a[1].first;

  rep(i,n)
    cout << ans[i] << endl;
}
