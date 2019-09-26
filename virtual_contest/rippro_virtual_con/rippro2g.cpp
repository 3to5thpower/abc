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

int n,q;
string s;
vint l,r;

int main(){
  cin >> n >> q >> s; l.resize(q);r.resize(q);
  rep(i,q) cin >> l[i] >> r[i];
  vint sigma(n,0);
  for(int i=1;i<n;++i){
    if(s[i-1]=='A'&&s[i]=='C') sigma[i]=sigma[i-1]+1;
    else sigma[i]=sigma[i-1];
  }

  rep(i,q){
    cout << sigma[r[i]-1]-sigma[l[i]-1] <<endl;
  }

  return 0;
}
