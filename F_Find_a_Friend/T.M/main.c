#include<stdio.h>
int f[100010],w[100010],mi;
void udw(int p,int add,int i){
  if(add==0)return ;
  if(f[p]<i)w[p] =add;
  else      w[p]+=add;
  f[p]=i;
  if(mi<0||w[mi]<w[p]||(w[mi]==w[p]&&mi>p))mi=p;
}
int MAX(int a,int b){return a<b?b:a;}
int rt[100110][100],rp[100110][110];
int main(){
  int i,j,k=100,l,n,m,e,b,q[100110],p[100110],t[100110],c[100110];
  int ta[100100],nt[100110],ii,no[100110];
  scanf("%d %d %d",&n,&m,&e);
  for(i=0;i<m;i++){
    scanf("%d %d %d",&t[i],&p[i],&q[i]);
    p[i]--;
    q[i]=1-q[i];
    f[p[i]]=1-f[p[i]];
  }
  for(i=0;i<n;i++){
    if(f[i]==0)continue;
    q[m  ]=1;
    p[m  ]=i;
    t[m++]=e;
  }
  //for(i=0;i<m;i++)printf("%d %d %d %d\n",i,q[i],p[i],t[i]);printf("\n");
  for(i=0;i<n;i++)ta[i]=f[i]=-1;
  for(i=0;i<m;i++){
    for(j=0;j<k;j++)rp[i][j]=-1;
  }
  for(i=0;i<m;i++){
    if(q[i]){
      for(j=0;rp[i][j]-p[i];j++);//printf("1:%d %d\n",i,j);
      c[i]=j;
      rp[i][j]=-1;
    }
    else{
      for(j=0;rp[i][j]+1;j++);//printf("0:%d %d\n",i,j);
      c[i]=j;
      rp[i][j]=p[i];
      rt[i][j]=t[i];
    }
    for(j=0;j<k;j++){
      rp[i+1][j]=rp[i][j];
      rt[i+1][j]=rt[i][j];
    }
  }
  /*OK
  for(i=0;i<m;i++){printf("%2d:",i);
    for(j=0;j<n;j++)printf("%2d %2d|",rp[i][j]+1,rt[i][j]);printf("\n");
  }printf("\n");//*/
  for(b=i=m;i--;){
    no[i]=b;
    if(q[i])b=i;
    nt[i]=ta[p[i]];
    ta[p[i]]=i;
  }
  /*OK
  for(i=0;i<n;i++){
    printf("%d:",i+1);
    for(j=ta[i];j+1;j=nt[j])printf("%d ",j);printf("\n");
  }printf("\n");//*/
  //for(i=0;i<m;i++)printf("%2d %2d %2d\n",i,no[i],p[no[i]]);printf("\n");
  for(i=0;i<n;i++){
    mi=-1;
    for(ii=ta[i];ii+1;ii=nt[nt[ii]]){
      for(j=no[ii];j<nt[ii];j=no[j]){
	//printf("%d %d %d %d %d\n",p[j]+1,t[j],t[ii],rt[j][c[j]],i+1);
	udw(p[j],t[j]-MAX(t[ii],rt[j][c[j]]),i);
      }
      for(l=0;l<k;l++){
	if(rp[j][l]<0)continue;
	//printf("%d %d %d %d %d\n",rp[j][l]+1,t[j],t[ii],rt[j][l],i+1);
	udw(rp[j][l],t[j]-MAX(t[ii],rt[j][l]),i);
      }
    }
    if(mi<0)mi=i?0:1;
    printf("%d\n",mi+1);
  }
  return 0;
}
