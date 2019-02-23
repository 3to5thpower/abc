#include<iostream>
using namespace std;

#define MAX_N 10000

int n,k;
int a[MAX_N];

bool dfs(int i,int sum){
  //n個決め終わったら今までの和がkと等しいか判定する
  if(i == n) return sum == k;

  //a[i]を使わない場合
  if(dfs(i + 1, sum)) return true;
  //a[i]を使う場合
  if(dfs(i + 1, sum + a[i])) return true;
  
  return false;
}

int main(){
  cin >> n;
  for(int i=0;i<n;++i) cin >> a[i];
  cin >> k;

  if(dfs(0,0)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
