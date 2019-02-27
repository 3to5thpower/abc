#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 99999999
#define rep(i,n) for(int i=0,temp=(int)(n);i<temp;++i) //vec.size()がnの時等の高速化
#define all(x) (x).begin,(x).end()
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

//a_1~a_nの中で足してkになるm個の組み合わせがあるかどうかを判定せよ。

int n;
vector<int> a;
int k;

bool dfs(int sum, int i){
  if(i == n) return sum == k;
  return dfs(sum,i+1) || dfs(sum+a[i],i+1);
  

}

int main(){
  cin >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];
  cin >> k;

  if(dfs(0,0)) cout << "Yes";
  else cout << "No";
  cout << endl;
  return 0;
}
