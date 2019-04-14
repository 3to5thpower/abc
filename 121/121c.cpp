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
#define vint vector<int>
#define vvint vector<vector<int>>

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n,m;

int main(){
  cin >> n >> m; 
  vector<pair<ll, ll>> ab(n);
  rep(i,n)cin >> ab[i].first >> ab[i].second;
  VSORT(ab);
  
  ll ans = 0;
  int i=0;
  while(m-ab[i].second>0){
    ans+=ab[i].first*ab[i].second;
    m-=ab[i].second;
    i++;
  }
  ans +=ab[i].first*m;

  cout << ans << endl;
  return 0;
}
