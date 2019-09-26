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


int main(){
  int a,b,k;
  cin >> a >> b >> k;
  int n = gcd(a,b);
  vector<int> v;
  for(int i=1;i<=n;++i){
    if((a%i==0)&&(b%i==0)) v.push_back(i);
  }
  sort(v.begin(),v.end(),greater<int>());
//  rep(i,n)cout << v[i] << endl;
  cout << v[k-1] << endl;

  return 0;
}
