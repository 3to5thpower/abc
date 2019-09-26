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

int a,b,c,k;

int bfs(int x,int y,int z,int id){
  if(id==k) return x+y+z;
  return max(bfs(x*2,y,z,id+1),max(bfs(x,y*2,z,id+1),bfs(x,y,z*2,id+1)));
}

int main(){
  cin >> a >> b >> c >>k;
  cout << bfs(a,b,c,0) << endl;
  return 0;
}
