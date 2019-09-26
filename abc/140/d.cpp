#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) 
#define repi(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))のように宣言できる
#define vin(v) rep(i,v.size()) {cin >> v[i];}
//最終奥義
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(all(v)),v.end());


signed main(void){
  int n,k;cin >> n >> k;

  vint b(n,0);
  
  rep(i,n){
    char c;cin >> c;
    if(c=='R')b[i]++;
  }


  int ltar=b[0],rtar=b[n-1];
  int l=0,r=n-1;

  rep(i,k+1){
    while(b[l]==ltar)l++;
    while(b[r]==rtar)r--;
    if(r<l&&i!=k){
      r=-1;
      break;
    }
    ltar=b[l];rtar=b[r];
  }
  vint a(n);
  rep(i,l-1)a[i]=b[0];
  repi(i,r+1,n)a[i]=b[n-1];
  repi(i,l,r+1){
    if(k%2)a[i]=abs(b[i]-1);
    else a[i]=b[i];
  }
//  rep(i,n)cout << a[i];
//  cout << endl;
  int ans=0;
  rep(i,n){
    int tar=a[i]?i-1:i+1;
    if(tar<0||n-1<tar)continue;
    if(a[i]==a[tar])ans++;
  }
  cout << ans << endl;


}
