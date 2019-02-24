#include<bits/stdc++.h>
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

int n,a,b,c;
vector<int> l;

int rec(int aa, int bb, int cc, int i){

  if(i == n-1){ 
    if(!aa||!bb||!cc) return INF;
    return abs(aa-a) + abs(bb-b) + abs(cc-c);
  }
  int res=INF;
  chmin(res,rec(a+l[i],b,c,i+1)+(a?10:0));
  chmin(res,rec(a,b+l[i],c,i+1)+(a?10:0));
  chmin(res,rec(a,b,c+l[i],i+1)+(a?10:0));
  chmin(res,rec(a,b,c,i+1));

  return res;
}



int main(){
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i,n) cin >> l[i];

  cout << rec(0,0,0,0) << endl;
}
