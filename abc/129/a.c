#include <stdio.h>

int max(int a, int b){
  return a<b?b:a;
}

int main(void){
  int p,q,r;
  scanf("%d",&p);
  scanf("%d",&q);
  scanf("%d",&r);
  int ans = p+r+q;
  ans -= max(p,max(q,r));
  printf("%d\n",ans);

  return 0;
}
