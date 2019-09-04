#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,i,min,ans=0,a,b,o=0,d[3][3]={0};
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  char s[1010];
  scanf("%d",&n);
  while(n--){
    scanf("%s",s);
    if(s[1]==0){
      if(s[0]=='A')d[0][1]++;
      if(s[0]=='O')o++;
      if(s[0]=='R')d[1][0]++;
      continue;
    }
    a=b=0;
    if(s[0]=='R')a=1;
    if(s[0]=='O'&&s[1]=='R')a=2;
    for(i=0;s[i+2];i++){
      if(s[i]=='A'&&s[i+1]=='O'&&s[i+2]=='R')ans++;
    }
    if(s[i+1]=='A')b=1;
    if(s[i]=='A'&&s[i+1]=='O')b=2;
    d[a][b]++;
  }
  a=d[0][1]+d[0][2]+d[1][0]+d[2][0];
  //d[2][2]+=o;
  //printf(" *-*, *-A,*-AO, R-*, R-A, R-AO,OR-*,OR-A,OR-AO,O\n");
  //for(i=0;i<9;i++)printf("  %d  ",d[i/3][i%3]);printf("  %d  0:%d\n",o,ans);
  //ans-=o;//- n n  n n n  n n n
  if(d[1][2]){
    ans+=d[1][2]-1;
    d[1][2]=1;
  }
  if(d[2][1]){
    ans+=d[2][1]-1;
    d[2][1]=1;
  }
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  // -   n    n   n   n   1     n    1    n
  //for(i=0;i<9;i++)printf("  %d  ",d[i/3][i%3]);printf("  %d  1:%d\n",o,ans);
  if(d[1][2]&&d[0][2]+d[2][2]+d[1][0]+d[1][1]){
    ans++;
    d[1][2]=0;
  }
  if(d[2][1]&&d[2][0]+d[2][2]+d[0][1]+d[1][1]){
    ans++;
    d[2][1]=0;
  }
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  // -   n    n   n   n   0     n    0    n
  //for(i=0;i<9;i++)printf("%d ",d[i/3][i%3]);printf("\n2:%d\n",ans);
  //for(i=0;i<9;i++)printf("  %d  ",d[i/3][i%3]);printf("  %d  2:%d\n",o,ans);
  if(d[2][2]&&d[1][1]){
    if(d[1][1]==d[2][2]){
      ans+=d[1][1]+d[2][2]-1;
      d[1][1]=d[2][2]=0;
      if(a)ans++;
    }
    else{
      min=MIN(d[1][1],d[2][2]);
      d[1][1]-=min;
      d[2][2]-=min;
      ans+=min*2;
    }
  }
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  // -   n    n   n   m   0     n    0    m
  //for(i=0;i<9;i++)printf("%d ",d[i/3][i%3]);printf("\n3:%d\n",ans);
  //for(i=0;i<9;i++)printf("  %d  ",d[i/3][i%3]);printf("  %d  3:%d\n",o,ans);
  min=MIN(d[0][1],d[2][0]);
  ans+=min;
  d[0][1]-=min;
  d[2][0]-=min;
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  // -   l    n   n   m   0     l    0    m
  //for(i=0;i<9;i++)printf("%d ",d[i/3][i%3]);printf("\n4:%d\n",ans);
  //for(i=0;i<9;i++)printf("  %d  ",d[i/3][i%3]);printf("  %d  4:%d\n",o,ans);
  min=MIN(d[0][2],d[1][0]);
  ans+=min;
  d[0][2]-=min;
  d[1][0]-=min;
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  // -   l    o   o   m   0     l    0    m
  //for(i=0;i<9;i++)printf("%d ",d[i/3][i%3]);printf("\n5:%d\n",ans);
  //for(i=0;i<9;i++)printf("  %d  ",d[i/3][i%3]);printf("  %d  5:%d\n",o,ans);
  ans+=MIN(d[0][2],d[1][1]);
  ans+=MIN(d[2][0],d[1][1]);
  d[1][1]=MAX(0,d[1][1]-MAX(d[0][2],d[2][0]));
  min=MIN(d[0][1],d[2][2]);
  ans+=min;
  d[0][1]-=min;
  min=MIN(d[1][0],d[2][2]);
  ans+=min;
  d[1][0]-=min;
  // printf("%d\n",ans);
  min=MIN(d[1][1],o);
  if(min){
    ans+=min-1;
    d[1][1]-=min;
    o-=min;
    if(a+d[1][1])ans++;
  }
  ans+=MIN(d[0][1]+d[2][1],MIN(o,d[1][0]+d[1][2]));
  //ans+=MAX(0,MIN(o,d[2][2]-MAX(d[0][1],d[1][0])));
  printf("%d\n",ans);
  return 0;
}
//A,ORAO,RA,ORAO,RAO,RA
