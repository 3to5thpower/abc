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

signed main(void){
  int n;cin >> n;
  vint a(n);vin(a);
  vint ans(n,0);int sum=0;
  for(int i=n-1;i>=0;--i){
    int ansi=0;
    for(int j=(i+1)*2-1;j<n;j+=i+1) ansi+=ans[j];
    if(ansi%2 != a[i]%2){
      ans[i]=1;sum++;
    }
  }
//  rep(i,n)cout << ans[i] <<endl;

  cout << sum << endl;
  rep(i,n) if(ans[i]==1) cout << i+1 << " ";
  cout << endl;
}
