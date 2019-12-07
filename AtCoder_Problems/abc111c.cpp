#include <algorithm>
#include<bits/stdc++.h>
#include <utility>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define INF 99999999
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
//最終奥義
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(all(v)),v.end());

signed main(void){
  int n;cin>>n;
  vint v1(n/2),v2(n/2);
  rep(i,n/2)
    cin >> v1[i] >> v2[i];
  
  multiset<int> s1,s2;
  rep(i,n/2){
    s1.insert(v1[i]);
    s2.insert(v2[i]);
  }

  vector<pint> a1, a2;
  auto i1=s1.begin(),i2=s2.begin();
  rep(i,s1.size())
    a1.push_back(make_pair(*i1,s1.count(*i1)));
  rep(i,s2.size())
    a2.push_back(make_pair(*i2,s2.count(*i2)));

  int ans=n;
  vfsort(a1,[](pint x,pint y){return x.second>y.second;});
  vfsort(a2,[](pint x,pint y){return x.second>y.second;});
  
  if(a1.size()==1&&a2.size()==1&&a1[0].first==a2[0].first){
    ans=n/2;
  }
  else if(a1[0].first==a2[0].first){
    bool one=a1[0].second>=a2[0].second;
    if(one){
      ans-=a1[0].second+a2[1].second;
    }else{
      ans-=a2[0].second+a1[1].second;
    }
  }else{
    ans-=a1[0].second+a2[0].second;
  }
  cout << ans << endl;

}
