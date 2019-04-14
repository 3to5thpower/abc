#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<cmath>

using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define all(x) (x).begin,(x).end()
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}


int n,t,a;
vector<int> h;
vector<int> temp;
int main(){
  cin >> n >> t >> a;
  h.resize(n);temp.resize(n);
  rep(i,n)cin >> h[i];
  int ans=-1,d=INF;
  rep(i,n){
    if(abs(t-h[i]*0.006-a) < d){
      d=abs(t-h[i]*0.006-a);
      ans = i;
    }
  }
  
  cout << ans+1 << endl;
  return 0;
}
