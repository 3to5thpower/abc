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
#define h(hxy) hxy.first
#define x(hxy) hxy.second.first
#define y(hxy) hxy.second.second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n;
typedef pair<int, pair<int,int>> hxy;
vector<hxy> hxy;

hxy three_same_hight(){
  int cnt=0,temp;
  rep(i,n){
    if(temp==h(hxy[i])) cnt++;
    if(cnt==2)return hxy[2];
    temp=h(hxy[i]);

  }
}

int main(){
  cin >> n; hxy.resize(n);
  rep(i,n) cin >> hxy[i].second.first >> hxy[i].second.second >> hxy[i].first;
  VSORT(hxy);
  if(h(hxy[0]) != h(hxy[1]) &&
      (x(hxy[0]) == 0 || x(hxy[0]) == 100 ||
       y(hxy[0]) == 0 || y(hxy[0]) == 100)){
    cout << x(hxy[0]) << y(hxy[0]) << h(hxy[0]) << endl;
    return 0;
  }

  
  return 0;
}
