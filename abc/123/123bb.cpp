#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define loop(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vin(v,n) rep(i,n) cin >> v[i]

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x) (+ 1 2)) => [](int x) -> int { return 1+2; }

int ten(int n){
  rep(i,10)
    if((n+i)%10==0) return n+i;
}

int main(){
  int ans=0,m=INF;
  vint v(5); vin(v,5);
  vfsort(v,[](int x,int y) -> int {
      if(x%10==0) return false;
      if(y%10==0) return true;
      return x%10<y%10; });
  ans+=v[0];
  loop(i,1,5) ans+=ten(v[i]);

  cout << ans << endl;
  return 0;
}
