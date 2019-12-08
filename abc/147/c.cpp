#include<bits/stdc++.h>
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
//最終奥義(使うときはINFも書き換えろ!!)
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(all(v)),v.end());

using human = pair<int,map<int,bool>>;
int n;
vector<human> xy;
int check_xy(human x,human y){
  rep(i,n){
    if(x.second.count(i+1)&&y.second.count(i+1)){
      if(x.second.at(i+1)!=y.second.at(i+1)){
        return 0;
      }
    }
  }
  if(x.second.count(y.first)&&y.second.count(x.first)&&
      x.second.at(y.first)==0&&y.second.at(x.first)==0)return 1;
  return 2;
}

int check_humans(vint check){
  vector<human> t;
  rfor(check,i){
    t.push_back(xy[i]);
    //cout << i;
  }//cout << endl;
  int l=t.size();
  int res=0;
  rep(i,l-1){
    repi(j,i+1,l){
      int tmp=check_xy(t[i],t[j]);
      if(!tmp)return 0;
      if(tmp==1)res++;
    }
  }
  return check.size()-res;
}

signed main(void){
  cin>>n;
  
  xy.resize(n);
  rep(i,n){
    xy[i].first=i+1;
    int a;
    cin>>a;
    rep(j,a){
      int t;cin>>t;
      cin>>xy[i].second[t];
    }
  }

  int ans=0;
  for(int i=1;i<(1<<n);++i){
    vint check;
    rep(j,n)if(i&(1<<j))check.push_back(j);
    if(check.size()<=1)continue;
    chmax(ans,check_humans(check));
  }
  cout << ans << endl;
}
