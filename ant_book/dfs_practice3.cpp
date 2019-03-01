#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>

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

int n,k;
vector<int> a;

bool dfs(int sum, int i){
  if(i == n) return k == sum;
  if(dfs(sum+a[i],i+1)) return true;
  if(dfs(sum,i+1)) return true;
  return false;
}

int main(){
  cin >> n; a.resize(n);
  rep(i,n) cin >> a[i]; cin >> k;
  if(dfs(0,0)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
