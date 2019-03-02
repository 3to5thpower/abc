#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>

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


//状態を表すクラスpairの場合typedefしておくと便利
typedef pair<int, int> P;

//入力
vector<vector<char>> maze;
int m,n,sx,sy,gx,gy;

vector<vector<int>> d;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int bfs(){

}

int main(){


  return 0;
}
