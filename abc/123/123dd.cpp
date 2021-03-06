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
#define vin(v) rep(i,v.size()) {cin >> v[i];}
#define rfor(v,x) for(const auto& x : v) //xはn番目ではなく各値を指す

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

#define downsort(v) vfsort(v,[](ll x,ll y) -> int{ return x>y; })

int x,y,z,k;
vector<ll> a,b,c,d,e;

int main(){
  cin >> x >> y >> z >> k; a.resize(x);b.resize(y);c.resize(z);
  vin(a);vin(b);vin(c);
  
  rfor(a,i)
    rfor(b,j) d.push_back(i+j);
  downsort(d);
  downsort(c);
  d.resize(k);
  rfor(c,i)
    rfor(d,j) e.push_back(i+j);
  downsort(e);

  rep(i,k) cout << e[i] << endl; 
  return 0;
}
