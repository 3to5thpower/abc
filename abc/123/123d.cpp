#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define vint vector<int>
#define vvint vector<vector<int>>

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}

int x,y,z; ll k;
vector<ll> a,b,c,ans;

void dp(ll k){
  ans[0]=a[0]+b[0]+c[0];
  
}

int main(){
  cin >> x >> y >> z >> k; a.resize(x);b.resize(y);c.resize(z);ans.resize(k);
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];
  VSORT(a);VSORT(b);VSORT(c);

  ll n=k/8,m=k%8;

  return 0;
}
