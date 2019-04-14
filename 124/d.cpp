#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define loop(i,start,end) for(int i=start,temp=(int)(end);i<end;++i)
#define rfor(v,x) for(const auto& x : v) //xは値を表す
#define vint vector<int>

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
//(lambda (x y) (< x y)) => [](int x, int y) -> int { return x<y; }


int main(){
  int n,k;
  vint bit;
  cin >> n >> k;
  string s;cin >> s;

  if(s[0]=='0') k=k*2;
  else k=k*2+1;
  
  int plus=0,minus=0;
  rep(i,n){
    if(s[i]=='1') {
      plus++;
      if(minus!=0){ 
        bit.push_back(minus);
        minus=0;
      }
    }
    else {
      minus++;
      if(plus!=0){ 
        bit.push_back(plus);
        plus=0;
      }
    }
  }
  if(plus!=0) bit.push_back(plus);
  if(minus!=0) bit.push_back(minus);

  vint sigma((int)bit.size()+1);
  sigma[0]=0;
  rep(i,(int)bit.size())
    sigma[i+1]= sigma[i] + bit[i];
  

  int ans=0;
  rep(i,sigma.size()-k){
    chmax(ans,sigma[k+i]-sigma[i]);
  }
  if(ans==0) ans++;
  cout << ans << endl;

}
