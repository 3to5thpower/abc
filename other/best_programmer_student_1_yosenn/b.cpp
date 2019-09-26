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
#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

signed main(void){
  int n,k;cin >> n >> k;
  int mod=1e9+7;
  vint a(n);vin(a);
  int s=0,t=0;
  rep(i,n){
    rep(j,n){
      s%=mod;t%=mod;
      if(i==j)continue;
      if(a[i]>a[j]){
        s++;
        if(i<j)t++;
      }
    }
  }
  int ka=k*t%mod;
  int sum;
  if(k%2==0)sum=k/2*s%mod*(k-1)%mod;
  else sum=(k-1)/2*s%mod*k%mod;
  int ans=(ka+sum)%mod;
  cout << ans << endl;
}
