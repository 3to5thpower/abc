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




int main(void){
  int n,ans=0;cin >> n;
  vector<string> s(n,"00");
  rep(i,n){
    string t;cin>>t;
    s[i][0]=t[0];
    s[i][1]=t.back();
    rep(i,t.size()-1){
      if(t[i]=='A'&& t[i+1]=='B') ans++;
    }
  }
 /* rep(i,n){
    cout << s[i] << endl;
  }*/
  int head_b=0,tail_a=0,ba=0;
  rep(i,n){
    if(s[i]=="BA"){
      ba++;
      continue;
    }
    if(s[i][0]=='B')head_b++;
    if(s[i][1]=='A')tail_a++;
  }
  int ma = max(head_b,tail_a), mi = min(head_b,tail_a);
  ans += mi;
  ans += min(ma-mi,ba);//ba++片方
  int temp=(ba-min(ma-mi,ba));
  ans += temp/2?temp/2+1:temp/2;//baba


  cout << ans << endl;


  return 0;
}
