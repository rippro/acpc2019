#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,r[100010],t[100010],p[100010],w[100010],i,j,m,d[2][100010]={};
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d %d %d",&r[i],&p[i],&w[i],&t[i]);
  
  for(i=0;i<2010;i++)d[1][i]=-1e9;
  for(i=0;i<n;i++){
    for(j=2000;j;j--){
      d[0][j]=MAX(d[0][j],d[0][j+1]);
      d[1][j]=MAX(d[1][j],d[1][j+1]);
    }
    for(j=r[i]+t[i];j>=r[i];j--){
      d[1][j-r[i]]=MAX(d[1][j-r[i]],MAX(d[0][j]+p[i],d[1][j]+w[i]));
    }
    for(j=2000;j;j--){
      d[0][j]=MAX(d[0][j],d[1][j]);
      d[1][j]=-1e9;
    }
  }
  printf("%d\n",d[0][1]);
  return 0;
}
