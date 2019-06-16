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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }


int main(void){
  int n,m,ans=0;cin >> n >> m;
  vector<pair<vint,bool>> sp(m);
  rep(i,m){
    int k;cin >> k;
    sp[i].first.resize(k);
    rep(j,k){ 
      cin >> sp[i].first[j];sp[i].first[j]--;
    }
  }
  rep(i,m) cin >> sp[i].second;


  rep(i,pow(2,n)){
    vint onoff(n);//iにおいてonにするスイッチ(bool)
    rep(j,n) onoff[j] = (i&(int)pow(2,j))==(int)pow(2,j);

    int flag=1;//spがすべてonかどうかのflag
    rfor(sp,t){
      int sum=0;
      rfor(t.first,x) sum+=onoff[x];
      flag&=sum%2==t.second;
      if(!flag)break;
    }
    if(flag) ans++;
  }

  cout << ans << endl;


  return 0;
}
