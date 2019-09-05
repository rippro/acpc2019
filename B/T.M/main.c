#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,i,x=0,y=0;
  char s[100010];
  scanf("%d %s",&n,s);
  for(i=0;s[i];i++){
    if('a'<=s[i]&&s[i]<='m')x++;
    if('n'<=s[i]&&s[i]<='z')x--;
    if('A'<=s[i]&&s[i]<='M')y++;
    if('N'<=s[i]&&s[i]<='Z')y--;
  }
  printf("%d\n",abs(x)+abs(y));
  for(i=0;i< y;i++)printf("A");
  for(i=0;i<-y;i++)printf("Z");
  for(i=0;i< x;i++)printf("a");
  for(i=0;i<-x;i++)printf("z");
  printf("\n");
  return 0;
}
