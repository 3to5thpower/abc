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

int n,m,ans;
vector<vector<char>> a;

//この関数は再帰によって隣接したすべてのwを.に置き換える役割のみを行う
void dfs(int x, int y){
  //今いるところを.に置き換える
  a[x][y]='.';

  //移動する方向を8ループ
  for(int i=-1;i<=1;++i){
    for(int j=-1;j<=1;++j){
      //x方向にi,y方向にj移動した場所をx1,y1とする
      int x1=x+i,y1=y+j;
      if(0<=x1&&)
    }
  }
}


int main(){
  cin >> n >> m;
  a.resize(n);rep(i,n)a[i].resize(m);
  rep(i,n)
    rep(j,m) cin >> a[i][j];
  ans = 0;
  solve();

  cout << ans << endl;

  return 0;
}
