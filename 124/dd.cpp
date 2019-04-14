#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define loop(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vin(v) rep(i,v.size()) {cin >> v[i];}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }

int main(){
  int n,k;cin >> n >> k;
  k=k*2+1;
  string s;cin >> s;

  vint v;int now=1,cnt=0;
  
  rep(i,n){
    if(now==ctoi(s[i])) cnt++;
    else {
      now^=1;
      v.push_back(cnt);
      cnt=1;
    }
  }
  if(now==ctoi(s.back())) v.push_back(cnt);
  if((int)v.size()%2==0) v.push_back(0); 

  rep(i,v.size()) cout << v[i];
  cout << endl;

  int ans=0;
  for(int i=0;i<v.size();i+=2){
    int sum=0;
    int left=i,right=min(i+k,(int)v.size());
    for(int j=left;j<right;++j)
      sum+=v[j];
    chmax(ans,sum);
  }

  cout << ans << endl;
  return 0;
}
