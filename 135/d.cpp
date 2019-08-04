#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) 
#define repi(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vin(v) rep(i,v.size()) {cin >> v[i];}
//最終奥義
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

vector<string> thirteens,plus5;

bool match(string x,string s){
  return ((x[0]==s[0]||s[0]=='?')&&
          (x[1]==s[1]||s[1]=='?')&&
          (x[2]==s[2]||s[2]=='?'));
}

int solve(string t,int i){
  string s;int cnt=0;
  reverse_copy(all(t),s.begin());
  if(i!=0){rfor(thirteens,x) if(match(x,s)) cnt++;}
  else{rfor(plus5,x) if(match(x,s))cnt++;}
  return cnt;
}



signed main(void){
  for(int i=0;13*i<1000;++i){
    string n=to_string(i*13),m=to_string(i*13+5);
    reverse(all(n));reverse(all(m));
    while(n.length()<3)n.push_back('0');
    while(m.length()<3)m.push_back('0');
    reverse(all(n));thirteens.push_back(n);
    reverse(all(m));plus5.push_back(m);
  }

/*
  string s;cin >> s;
  reverse(all(s));
  while(s.length()%3!=0)s.push_back('0');
  ll ans=1;
  for(int i=0;i<s.length();i+=3){
    ans*=f(s.substr(i,3),i);
  }

  cout << ans << endl;*/
}
