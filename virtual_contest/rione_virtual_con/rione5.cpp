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
vint a,t;

bool judge(){
  VSORT(a);
  if(n%2!=0){
    t.push_back(0);
    rep(i,(n-1)/2){
      t.push_back((i+1)*2);
      t.push_back((i+1)*2);
    }
  }
  else{
    rep(i,n/2){
      t.push_back(2*(i+1)-1);
      t.push_back(2*(i+1)-1);
    }
  }
//  for(auto x: t) cout << x;
  return a == t;
}

int main(){
  cin >> n; a.resize(n);
  rep(i,n) cin >> a[i];
 
  ll ans=0;
  
  if(judge()){
    ans=1;
    rep(i,n/2){
      ans = ans*2 % 1000000007;
    }
  }
  cout << ans << endl;

  return 0;
}
