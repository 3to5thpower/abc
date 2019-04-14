#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define loop(i,start,n) for(int i=start;i<n;++i)
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n);
#define VSORT(v,f) sort(v.begin(), v.end(),f);
#define vint vector<int>
#define vvint vector<vector<int>>

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}

int tendiff(int n){
  if(n%10==0) return n;
  rep(i,10){
    if((n+i)%10 == 0) return n+i;
  }
}

int main(){
  int ans=0;
  vint v(5);rep(i,5) cin >> v[i];
  VSORT(v,[](int x,int y) -> int {
          return ( tendiff(x)-x < tendiff(y)-y );
          }  );
  ans+=v[4];
  rep(i,4) ans+=tendiff(v[i]);
  

  cout << ans << endl;
  


  return 0;
}
