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
  int h,w;cin >> h >> w;
  vector<vector<char>> a(h);
  rep(i,h) a[i].resize(w);
  rep(i,h)
    rep(j,w) cin >> a[i][j];

  rep(i,h){
    bool flag=true;
    rep(j,w) flag &= a[i][j]=='.';
    if(flag){
      rep(j,w) a[i][j] = '-';
    }
  }

  rep(j,w){
    bool flag=true;
    rep(i,h) flag &= a[i][j]=='.' || a[i][j]=='-' ;
    if(flag){
      rep(i,h) a[i][j] = '-';
    }
  }

  rep(i,h){
    bool p=true;
    rep(j,w){
      if(a[i][j]=='-'){
        p&=true;
        continue;
      }
      p=false;
      cout << a[i][j];
    }
    if(!p) cout << endl;
  }

  return 0;
}
