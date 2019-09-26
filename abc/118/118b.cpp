#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int a[n][m];
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      a[i][j] = 0;
  for(int i=0;i<n;++i){
    int k;
    cin >> k;
    for(int j=0;j<k;++j)
      cin >> a[i][j];
  }

  
  int count = 0;
  for(int f=1;f<=m+1;++f){
    int g = 0;
    for(int i=0;i<n;++i){
      for(int j=0;j<m;++j)
        if(a[i][j] == f) g++;
    }
    if(g == n) count++;
  }
  cout << count << endl;

  return 0;
}
