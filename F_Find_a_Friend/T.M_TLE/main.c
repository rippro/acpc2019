#include<stdio.h>
int s[1010][1010],d[1010];
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,m,t,p,q,i,j,e;
  scanf("%d %d %d",&n,&m,&e);
  for(i=0;i<n;i++)d[i]=-1;
  for(i=0;i<m;i++){
    scanf("%d %d %d",&t,&p,&q);
    p--;
    if(!q){
      for(j=0;j<n;j++){
	if(p==j||d[j]<0)continue;
	s[p][j]+=t-MAX(d[p],d[j]);
	//printf("!%d %d %d %d %d %d\n",s[p][j],p,j,t,d[p],d[j]);
      }
      d[p]=-1;
    }
    else{
      d[p]=t;
    }
    //for(j=0;j<n;j++)printf("%d ",d[j]);printf("\n");
    
  }//*
  for(i=0;i<n;i++){
    if(d[i]<0)continue;
    for(j=0;j<n;j++){
      if(i==j||d[j]<0)continue;
      s[i][j]+=e-MAX(d[i],d[j]);
      //printf("!%d %d %d %d %d %d\n",s[i][j],i,j,t,d[i],d[j]);
    }
    d[i]=-1;
  }//*/
  for(i=0;i<n;i++){
    m=i?0:1;
    for(j=0;j<n;j++){//printf("%d ",s[i][j]);
      if(i==j)continue;
      if(s[i][m]+s[m][i]<s[i][j]+s[j][i])m=j;
    }
    printf("%d\n",m+1);
  }
  return 0;
}
