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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}


int n,q;
string s;
vector<char> t,d;

int main(){
  cin >> n >> q >> s; t.resize(q);d.resize(q);
  rep(i,q) cin >> t[i] >> d[i];

  //ゴーレムの数を管理
  vint gorem(n,1);

  //文字と番地のペアのハッシュ
  unordered_map<char, vint> graph;
  rep(i,n){
    char tem=s[i];
    graph[tem].push_back(i);
  }
  rep(i,q){ //各問について
    char t_i=t[i];
    for(auto& pos:graph[t_i]){
      int temp=gorem[pos];
      gorem[pos]=0;
      if(d[i]=='R'){
        if(pos+1<n)gorem[pos+1]+=temp;
      }
      else{
        if(pos>0)gorem[pos-1]+=temp;
      }
    }
  }
  
  int ans = 0;
  rep(i,n) ans+=gorem[i];
  cout << ans << endl;
  return 0;
}
