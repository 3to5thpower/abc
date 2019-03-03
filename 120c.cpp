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

string s;
vector<char> v;
bool removablep(int i){
  if(v[i]=='0'&&v[i+1]=='1' ||
      v[i]=='1'&&v[i+1]=='0')
    return true;
  return false;
}

int solve(int i){
  if(i==s.length()) return s.length()-(int)v.size();
  v.push_back(s[i]);
  while(removablep(v.size()-2)){
    v.pop_back();
    v.pop_back();
  }
  return solve(i+1);
}

int main(){
  cin >> s;
  cout << solve(0) << endl;
  return 0;
}
