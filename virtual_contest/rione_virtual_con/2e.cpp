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

int ctoi(char c){
  if(c>='0'&&c<='9') return c-'0';
  return 0;
}


char op(int i){
  if(i==-1) return '-';
  else return '+';
}

int main(){
  string s;vint n(4);
  cin >> s;
  rep(i,4) n[i]=ctoi(s[i]);
  
  for(int i=-1;i<=1;i+=2){
    for(int j=-1;j<=1;j+=2){
      for(int k=-1;k<=1;k+=2){
        int sevenp=n[0]+i*n[1]+j*n[2]+k*n[3];
        if(sevenp==7){
          cout << n[0] << op(i) << n[1] << op(j) << n[2] << op(k) << n[3] << "=7" << endl;
          return 0;
        }
      }
    }
  }


  return 0;
}
