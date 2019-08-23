#include<stdio.h>
int main(){
  int n,a,b,m;
  char s[10];
  scanf("%d %d %d %d",&n,&a,&b,&m);
  while(m--){
    scanf("%s",s);
    if(s[0]=='n')n+=a;
    if(s[0]=='t')n+=b;
    if(s[0]=='k')n=0;
  }
  printf("%d\n",n);
  return 0;
}
  
