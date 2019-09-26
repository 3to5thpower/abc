#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i)
#define vint vector<int>

int ctoi(char c) {return c-'0';}

vint v,u;

int solve(){
  int ans=0;
  rep(i,v.size())
    if(v[i]^u[i]) ans++;
  return ans;
}

int main(){
  string s;cin >> s;
  v.resize(s.length());
  u.resize(s.length());
  
  rep(i,s.size())
    v[i]=ctoi(s[i]);

  for(int i=0;i<s.size();i+=2){
      u[i]=v[0];
      u[i+1]=!v[0];
  }

  cout << solve() << endl;
}
