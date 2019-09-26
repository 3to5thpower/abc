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

ll n,cnt=0;
void dfs(ll num,int flag){
  if(num>n) return;

  if(flag==7) cnt++;

  dfs(num*10+3,flag|1);
  dfs(num*10+5,flag|2);
  dfs(num*10+7,flag|4);

}


int main(){
  cin >> n;
  dfs(0,0);
  cout << cnt << endl;
  return 0;
}
