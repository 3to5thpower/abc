
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


typedef pair<int, int> P;

vector<vector<char>> maze;//迷路を表す文字配列(m*n)
int n,m;
int sx,sy;//start
int gx,gy;//goal

vvint d;//各点までの最短距離の配列

//移動4方向のベクトル
int dx[4]={1,0,-1,-1}, dy[4]={0,1,0,-1};

//(sx,sy)->(gx,gy)への最短距離を計算する(たどり着かない時はINF)
int bfs(){
  queue<P> que;

  //すべての点をINFで初期化
  rep(i,n)
    rep(j,m) d[i][j]=INF;
  //スタート地点をキューに入れて最短距離を0にする
  que.push(P(sx,sy));
  d[sx][sy]=0;

  //キューが空になるまでループ 
  while(que.size()){
    //キューの最初の要素を取り出す
    P p = que.front();que.pop();
    //pがゴールなら探索終了
    if(p.first == gx && p.second == gy) break;

    //移動4方向をループ
    rep(i,4){
      //移動後の点を(sx,sy)とする
      int nx = p.first + dx[i], ny=p.second + dy[i];

      //移動が可能かどうか、既訪かどうかの判定
      if(0<=nx && nx<n && 0<=ny && ny<m &&
          maze[nx][ny] != '#' && d[nx][ny]==INF){
        //移動できるならキューに入れ、その点をpからの距離+1で確定する
        que.push(P(nx,ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

int main(){
  cin >> n >> m;maze.resize(n);rep(i,n)maze[i].resize(m);
  d.resize(n);rep(i,n)d[i].resize(m);
  rep(i,n)
    rep(j,m){
      cin >> maze[i][j];
      if(maze[i][j]=='S'){
        sx=i;sy=j;
      }
      if(maze[i][j]=='G'){
        gx=i;gy=j;
      }
    }
  int ans = bfs();
  cout << ans << endl;
  return 0;
}
