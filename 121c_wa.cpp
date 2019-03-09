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

int n,m;
vector<ll> a,b;
ll ans=0;

ll operate(int m){
  ll mc;
  //最小価格を探索
  vector<ll>::iterator minIt = min_element(a.begin(),a.end());
  size_t pos = distance(a.begin(), minIt);
  mc=a[pos];
  a[pos]=INF;

  if(m-b[pos]>0){ 
    ans += mc * b[pos];
    return operate(m-b[pos]);
  }
  else{
    ans+= mc * m;
    return ans;
  }
}

signed main(){
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);b.resize(n);
  rep(i,n)cin >> a[i] >> b[i];
  cout << operate(m) << endl;

}
