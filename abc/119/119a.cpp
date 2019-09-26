#include <iostream>
#include <string>
using namespace std;
int main(){
  string s; cin >> s;
  int year = stoi(s.substr(0,4)), month = stoi(s.substr(5,2)), day = stoi(s.substr(8,2));
  if(year < 2019) cout << "Heisei" << endl;
  else if(month <= 4) cout << "Heisei" << endl;
  else cout << "TBD" << endl;

  return 0;
}
