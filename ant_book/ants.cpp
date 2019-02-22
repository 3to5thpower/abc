#include<iostream>
using namespace std;


int main(){
  int l,n;
  cin >> l >> n;
  int x[n]; for(int i=0;i<n;++i) cin >> x[i];
  int mi=0,ma=0;
  
  for(int i=0;i<n;++i){
    mi=max(mi, min(x[i],l-x[i]));
  }
  
  for(int i=0;i<n;++i){
    ma=max(ma, max(x[i],l-x[i]));
  }
  cout << "min= " << mi << "\nmax= " << ma << endl;

  return 0;
}
