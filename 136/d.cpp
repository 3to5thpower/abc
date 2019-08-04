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

signed main(void){
  string s;cin >> s;
  int n=s.length();
  vint ans;char c='R';int cnt=0;vint pos;
  rep(i,n){
    if(c==s[i])cnt++;
    else{
      ans.push_back(cnt);
      cnt=1;
      c=s[i];
      pos.push_back(i-1);
    }
  }ans.push_back(cnt);
  for(int i=0;i<(int)ans.size();i+=2){
    int mid=(ans[i]+ans[i+1])/2;
    if(ans[i]%2==ans[i+1]%2){
      ans[i]=mid;
      ans[i+1]=mid;
    }else if(ans[i]%2){
      if(ans[i]>ans[i+1]){
        ans[i]=mid+1;
        ans[i+1]=mid;
      }else{
        ans[i]=mid;
        ans[i+1]=mid+1;
      }
    }else{
      if(ans[i]<ans[i+1]){
        ans[i]=mid+1;
        ans[i+1]=mid;
      }else{
        ans[i]=mid;
        ans[i+1]=mid+1;
      }
    }
  }
  int itr=0;
  rep(i,n){  
    if(i!=pos[itr])cout << 0 << " ";
    else cout << ans[itr++] << " ";
  }
  cout << endl;

}
