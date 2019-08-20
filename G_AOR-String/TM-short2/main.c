#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
int ans=0;
int f(int *a,int *b){
  int min=MIN(*a,*b);
  *a-=min;
  *b-=min;
  ans+=min;
  return min;
}
int main(){
  int n,i,min,a,b,o=0,d[3][3]={0};
  char s[1010]={0};
  scanf("%d",&n);
  while(n--){
    scanf("%s",s+1);
    a=b=0;
    if(s[1]=='R')a=1;
    if(s[1]=='O'&&s[2]=='R')a=2;
    if(s[1]=='O'&&s[2]== 0 )o++;
    for(i=0;s[i+2];i++){
      if(s[i]=='A'&&s[i+1]=='O'&&s[i+2]=='R')ans++;
    }
    if(s[i+1]=='A')b=1;
    if(s[i]=='A'&&s[i+1]=='O')b=2;
    d[a][b]++;
  }
  a=d[0][1]+d[0][2]+d[1][0]+d[2][0];
  ans+=d[1][2]+d[2][1];
  d[1][2]=(d[1][2]==0||d[0][2]+d[2][2]+d[1][0]+d[1][1])?0:1;
  d[2][1]=(d[2][1]==0||d[2][0]+d[2][2]+d[0][1]+d[1][1])?0:1;
  ans-=d[1][2]+d[2][1];
  d[0][1]+=d[2][1];
  d[1][0]+=d[1][2];
  min=f(&d[1][1],&d[2][2]);
  ans+=min;
  if(min&&d[1][1]+d[2][2]+a==0)ans--;
  d[0][2]+=f(&d[0][1],&d[2][2]);
  d[2][0]+=f(&d[1][0],&d[2][2]);
  d[0][1]+=f(&d[0][2],&d[1][1]);
  d[1][0]+=f(&d[2][0],&d[1][1]);
  f(&d[0][1],&d[2][0]);
  f(&d[0][2],&d[1][0]);
  min=f(&d[1][1],&o);
  if(min&&a+d[1][1]==0)ans--;
  ans+=MIN(MIN(d[0][1],d[1][0]),o);
  printf("%d\n",ans);
  return 0;
}
