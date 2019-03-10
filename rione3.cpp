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
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define vint vector<int>
#define vvint vector<vector<int>>

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n;
vint a,b1,b2;

int main(){
  cin >> n; a.resize(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    if(i%2==0) b1.push_back(a[i]);
    else b2.push_back(a[i]);
  }
  if(n%2==0){
  rep(i,n/2) cout << b2[n/2-1-i] << ' ';
  for(auto x: b1) cout << x << ' ';
  }
  else{
    rep(i,n/2+1) cout << b1[n/2-i] << ' ';
    for(auto x:b2) cout << x << ' ';
  }
  cout << endl;

  return 0;
}
