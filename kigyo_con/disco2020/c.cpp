#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define INF 99999999
#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i)) 
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(v,x) for(const auto& (x) : (v)) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))のように宣言できる
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(all(v)),v.end());

signed main(void){
  int h,w,k;cin >> h >> w >> k;
  char s[h][w];
  rep(i,h)
    rep(j,w) cin >> s[i][j];

  int ans[h][w];
  vint z;

  int out=0;
  bool p;//今表示してる区画にもう苺があるか
  bool e;//その行に苺が存在するか
  rep(i,h){
    p=false;
    e=false;
    out++;
    rep(j,w){
      if(s[i][j]=='#'){
        e=true;
        if(!p){
          p=true;
        }else out++;
        ans[i][j]=out;
      }else
        ans[i][j]=out;
    }
    if(!e)z.push_back(i);
  }


  rfor(z,e){
    repi(i,e,h)
      rep(j,w)ans[i][j]--;
  }

  rfor(z,i){
    if(i!=0)
      rep(j,w)ans[i][j]=ans[i-1][j];
    else 
      rep(j,w)ans[i][j]=ans[i+1][j];
  }
  for(int i=h-2;i>=0;i--)
    rep(j,w){
      if(ans[i][j]==0){
        ans[i][j]=ans[i+1][j];
      }
    }

  rep(i,h){
    rep(j,w){
      printf("%d ",ans[i][j]);
    }
    puts("");
  }
}
