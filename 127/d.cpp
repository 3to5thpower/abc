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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

#define pint pair<int,int>

bool cmp(pint x, pint y){
  return x.first>y.first;
}

signed main(void){
  int n,m;cin >> n >> m;
  vint a(n);vin(a);
  vector<pair<int,int>> p(m);
  vsort(a);
  rep(i,m)cin >> p[i].second >> p[i].first;
  sort(all(p),cmp);
  
  int t=0;
  rep(i,m){
    int b=p[i].second, c=p[i].first;
    while(a[t]<c && b>0){
      a[t++]=c;
      b--;
    }
  }

  cout << accumulate(all(a),0LL) << endl;

  return 0;
}
