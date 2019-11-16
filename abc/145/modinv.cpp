#include<iostream>
using namespace std;
using ll = long long;

//x^-1(mod.p)を求めるmodinv

//まずax+by=1となるような(x,y)を求める関数
//(これはa^-1 mod bを求めるにはax+by=1となるxを求めればよいため。)
void extGCD(ll a, ll b, ll &x, ll &y){
  if(b==0){
    x=1;
    y=0;
    return;
  }
  ll s,t;
  extGCD(b,a%b,y,x);
  y-=a/b*x;
}

//負の数にも対応したmod
inline ll mod(ll a, ll m){
  return (a%m + m)%m;
}

//逆元計算
ll modinv(ll a,ll m){
  ll x,y;
  extGCD(a,m,x,y);
  return mod(x,m);
}

int main(void){
  cout << modinv(3,7) << endl;
}
