#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pint =  pair<int,int>;

#define INF 99999999
#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i)) 
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(v,x) for(const auto& (x) : (v)) //xは値を表す
#define aint(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(aint((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))のように宣言できる
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義
#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int ctoi(char c) {return c-'0';}
//lambda式 -> [&](int x, int y){return x<y;}
//vector内の重複を削除-> v.erase(unique(aint(v)),v.end());

#define MAX 1000002
#define MOD 1000000007
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

bool knight(pint p){
  int x=p.first,y=p.second;
  if((x+y)%3!=0)return false;
  if(x*2<y)return false;
  if(x>2*y)return false;
  return true;
}


signed main(void){
  COMinit();
  pint t;cin>>t.first>>t.second;
  if(!knight(t)){
    cout << 0 << endl;
    return 0;
  }

  int x=t.first,y=t.second;
  int h=0,w=0;
  if(x==y){
    w=x/3;
    h=y/3;
  }else if(x>=y){
    while(x-(w*3)!=2*(y-(h*3))){
      w++;h++;
    }
    w+=y-(w*3);
  }else{
    while((y-h*3)!=2*(x-(w*3))){
      w++;h++;
    }
    h+=x-(h*3);
  }

  printf("%lld\n",COM(h+w,w)%MOD);

}
