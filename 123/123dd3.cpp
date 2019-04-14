#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define loop(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort(v, v+n)
#define vsort(v) sort(v.begin(), v.end())
#define vfsort(v,lambda) sort(v.begin(),v.end(),lambda)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vin(v) rep(i,v.size()) {cin >> v[i];}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }
#define dsort(v) vfsort(v,[](ll x,ll y) -> int{return x>y;})

using Data = pair<ll,vint>;

int k;
vector<ll> a,b,c;

int main(){
  vint n(3); vin(n); //x,y,z
  cin >> k;
  vector<vector<ll>> v(3);
  rep(i,3){
    v[i].resize(n[i]);
    rep(j,n[i]) cin >> v[i][j];
    dsort(v[i]);
  }

  priority_queue<Data> que;
  set<Data> se;
  que.push(Data(v[0][0]+v[1][0]+v[2][0],vint({0,0,0})));

  rep(i,k){
    auto c = que.top();que.pop();
    cout << c.first << endl;

    //次の3候補
    rep(i,3){
      if(c.second[i]+1<n[i]){
        ll sum = c.first + (v[i][c.second[i]+1] - v[i][c.second[i]]);
        auto num = c.second; num[i]++;
        auto d = Data(sum,num);

        //すでにpushされたもの以外
        if(!se.count(d)) se.insert(d), que.push(d);
      }
    }
  }
  return 0;
}

