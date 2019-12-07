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

signed main(void){
  int n;cin >> n;
  vector<pint> node(n);
  multiset<int> t;
  int cn=0;
  rep(i,n-1){
    int a,b;cin >> a >> b;
    t.insert(a);t.insert(b);
    node[i].first=a;
    node[i].second=b;
  }
  
  
  rep(i,n-1){
    int c=t.count(i+1);
    chmax(cn,c);
  }

  vector<set<int>> ans(n);
  vint color(cn);
  rep(i,cn)color[i]=i+1;
  cout << cn << endl;

  if(cn==n-1){
    rep(i,n-1)cout << i+1 << endl;
    return 0;
  }
  rep(i,n-1){
    int l=node[i].first-1;
    int r=node[i].second-1;
    int res;
    rfor(color,c){
      if(ans[l].count(c)==0&&
          ans[r].count(c)==0){
        ans[l].insert(c);
        ans[r].insert(c);
        res=c;
        break;
      }
    }
    cout << res << endl;
  }
}
