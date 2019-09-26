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

bool good(string n){
  if(n[0]==n[1]&&n[1]==n[2]) return true;
  if(n[1]==n[2]&&n[2]==n[3]) return true;
  return false;
}

int main(){
  string n;cin >> n;
  if(good(n)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
