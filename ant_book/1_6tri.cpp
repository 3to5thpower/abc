#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;++i) cin >> a[i];

  int sum = 0;
  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j){
      for(int k=j+1;k<n;++k){
        int len=i+j+k;
        int ma = max(i, max(j,k));
        if(len-ma> ma) sum=len;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
