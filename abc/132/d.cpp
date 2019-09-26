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

ll MOD=1e9+7;

vint fact(2000,1);


int _div(int n,int r){
  ll res=1;
  for(int i=n+1,j=1;i<n+r;++i,++j){
    res*=i;res/=j;
    res%=MOD;
  }
  return res;
}

signed main(void){
  int n,k;cin >> n >> k;
  repi(i,1,1999) fact[i]=(i*fact[i-1])%MOD;
  rep(i,k){
    int b = _div(k-(i+1),i+1);cout << "b = " << b << endl;
    int r = _div(n-k-i,i+2); cout << "r = " << r << endl;
    cout << (b*r) % MOD << endl;
  }
  return 0;
}
