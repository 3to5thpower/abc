#include<bits/stdc++.h>
using namespace std;

#define int long long
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

int n,m;
vint divs;
void set_divs(){
  for(int i=1;i*i<=m;++i){
    if(m%i==0){
      divs.push_back(i);
      if(i*i!=m)divs.push_back(m/i);
    }
  }
}
signed main(){
  cin >> n >> m;
  set_divs();
  int ans=0;
  for(auto div:divs){
    if(m>=div*n) chmax(ans,div);
  }
  cout << ans << endl;

  return 0;
}
