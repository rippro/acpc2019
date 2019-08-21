#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,d[310][310],i,j,k;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)d[i][j]=1;
    d[i][i]=0;
  }
  while(m--){
    scanf("%d %d",&i,&j);
    d[i-1][j-1]=0;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++)d[j][k]=MIN(d[j][k],d[j][i]+d[i][k]);
    }
  }
  for(i=0;i<n;i++){
    for(j=k=0;j<n;j++){
      if(d[i][j]==0){
	if(k)printf(" ");
	printf("%d",j+1);
	k=1;
      }
    }
    printf("\n");
  }
  return 0;
}
				    
