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

ll cmb5(int n){
  int x=1;
  for(int i=5;i<=n-1;i--)x*=i;
  rep(i,n) x/=(i+1);
  return x;
}

signed main(void){
  int n;cin >> n;
  int march[5]={0,0,0,0,0};
  rep(i,n){
    string s;cin >> s;
    if(s[0]=='M')march[0]++;
    if(s[0]=='A')march[1]++;
    if(s[0]=='R')march[2]++;
    if(s[0]=='C')march[3]++;
    if(s[0]=='H')march[4]++;
  }
  ll ans=0;
  rep(i,5)
    repi(j,i+1,5)
      repi(k,j+1,5){
        ans += march[i]*march[j]*march[k];
      }


    cout << ans << endl;


}
