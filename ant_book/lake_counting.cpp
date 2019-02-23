#include<iostream>
using namespace std;

#define MAX_N 100
int n,m;
char garden[MAX_N][MAX_N];

void dfs(int x, int y){
  garden[x][y] = '.';

  for(int i=-1;i<=1;++i){
    for(int j=-1;j<=1;++j){
      int nx = x + i, ny = y + j;

      if(0<=nx&&nx<n && 0<=ny&&ny<n && garden[nx][ny] == 'w') dfs(nx,ny);
    }
  }
}

int main(){
  n=0;m=0;
  cin >> n >> m;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      cin >> garden[i][j];
  int ans=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      dfs(i,j);
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
