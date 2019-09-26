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

string s;

bool acgt(char c){
  if(c=='A'||c=='C'||c=='G'||c=='T') return true;
  return false;
}

int main(){
  cin >> s;
  int len=(int)s.length();
  int ans=0;
  int temp=0;
  rep(i,len){
    if(!acgt(s[i])){
      temp=0;
      continue;
    }
    temp++;
    if(ans<temp) ans=temp;
  }
  
  cout << ans << endl;
  return 0;
}
