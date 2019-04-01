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

bool atgc(char b){
  if(b=='A'||b=='T'||b=='C'||b=='G') return true;
  return false;
}

bool atgcs(string s){
  rep(i,s.length()){
    if(!atgc(s[i])) return false;
  }
  return true;
}

int main(){
  cin >> s;
  int len=0;
  rep(i,s.length()){
    for(int j=i;j<(int)s.length();j++){
      if(atgcs(s.substr(i,j-i+1))){
        chmax(len,j-i+1);
      }
    } 
  }
  cout << len << endl;

  return 0;
}
