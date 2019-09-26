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


int n,m,c;
vector<int> b;
vector<vector <int>> a;

bool sign(int i){
  int sum=c;
  rep(j,m)sum+=a[i][j]*b[j];
  return sum>0;
}

int main(){
  cin >> n >> m >> c;
  //aはn行m列,bはm次元配列
  b.resize(m);a.resize(n);rep(i,n)a[i].resize(m);
  rep(i,m)cin >> b[i];
  rep(i,n)
    rep(j,m) cin >> a[i][j];
  int ans=0;
  rep(i,n){
    if(sign(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
