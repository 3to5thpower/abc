#include <iostream>
#include <vector>
using namespace std;

int n,a,b,c,cost=0,a1,b1,c1;
vector<int> l;

int min3(int n){
  if(abs(a1-n) < abs(b1-n) && abs(a1-n) < abs(c1-n)){
    
    if(a==a1) return a1=abs(a1-n);
    return a1=abs(a1-n)+10;
  }
  if(abs(b1-n) < abs(c1-n) && abs(b1-n) < abs(a1-n)){
    if(b==b1) return b1=abs(b1-n);
    return b1=abs(b1-n)+10;
  }
  if(c==c1) return c1=abs(c1-n);
  return c1=abs(c1-n)+10;
}

int main(){
  cin >> n >> a >> b >> c;
  a1=a;b1=b;c1=c;
  for(int i=0;i<n;++i) cin >> l[i];

  for(int i=0;i<n;++i){
    cost+=min3(l[i]);
  }
  cout << cost << endl;
  return 0;
}

