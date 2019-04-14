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

int n,t;
vector<pair<int,int>> ct;
int main(){
  cin >> n >> t;
  ct.resize(n);
  rep(i,n)cin >> ct[i].first >> ct[i].second;
  VSORT(ct);

  rep(i,n){
    if(ct[i].second <= t){ 
      cout << ct[i].first << endl;
      return 0;
    }
  }
  cout << "TLE" << endl;

  return 0;
}
