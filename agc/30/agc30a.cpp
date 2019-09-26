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

int main(){
  int a,b,c; cin >> a >> b >> c;
  int ans=0;
  if(a>c || c==0) {ans=b+c; cout << ans << endl; return 0;}
  while(a>0){
    c--;a--;ans++;
  }
  if(b>c){ans+=b+c; cout << ans << endl; return 0;}
  while(b>0){
    c--;b--;ans+=2;
  }
  if(c>0)ans++;

  cout << ans << endl;

  return 0;
}
