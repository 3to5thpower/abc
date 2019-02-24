#include <iostream>
#include <string>

using namespace std;

int main(){
  int n; cin >> n;
  double ans = 0;
  for(int i=0;i<n;++i){
    double x; string u;
    cin >> x >> u;
    if(u == "JPY") ans += x;
    else ans += x * 380000.0;
  }

  cout << ans << endl;
  return 0;
}
