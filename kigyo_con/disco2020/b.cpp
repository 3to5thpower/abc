#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define INF 2020202025
#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i)) 
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(v,x) for(const auto& (x) : (v)) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))のように宣言できる
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義
#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(all(v)),v.end());

signed main(void){
  int n;cin >> n;
  vint a(n);vin(a);

  vint r(n),l(n);
  r[n-1]=a[n-1];l[0]=a[0];
  repi(i,1,n)
    l[i]=l[i-1]+a[i];
  for(int i=n-2;i>=0;i--)
    r[i]=r[i+1]+a[i];
  int d=INF;
  rep(i,n-1)
    chmin(d,abs(l[i]-r[i+1]));

  printf("%lld\n",d);

}
