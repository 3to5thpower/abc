#include<bits/stdc++.h>

using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define INF 1000000000000000001
#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i)) 
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(v,x) for(const auto& (x) : (v)) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))のように宣言できる
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義(使うときはINFも書き換えろ!!)
#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(all(v)),v.end());

int digit(int n){return (int)log10(n)+1;}
int a,b,x;

int nibutan(int max,int min){
  int mid=(max+min)/2;
  if(max-min<2){
    if(a*max+b*digit(max)<=x)return max;
    if(a*min+b*digit(min)<=x)return min;
    return 0;
  }
  if(a*mid+b*digit(mid)<=x)
    return nibutan(max,mid);
  else
    return nibutan(mid,min);
}

signed main(void){
  cin >> a >> b >> x;
  int max=1000000000,min=1;
  cout << nibutan(max,min) << endl;
}
