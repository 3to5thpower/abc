#include<stdio.h>

int main(void){
  char s[4];scanf("%s",s);
  if(s[0]==s[1]|s[1]==s[2]|s[2]==s[3])
    puts("Bad");
  else puts("Good");

  return 0;
}
