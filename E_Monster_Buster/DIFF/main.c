#include<stdio.h>
int n,d[100010],p[100],a[100],w[100],t[100],u[100],ans=0;
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
void f(int r,int mt){
  int i,j,s;
  for(i=0;i<n;i++){
    if(p[i]>=mt){
      for(j=s=0;j<n;j++)u[j]=0;
      for(j=0;j<r;j++){
	if(u[d[j]])s+=w[d[j]];
	else       s+=a[d[j]];
	u[d[j]]=1;
      }
      ans=MAX(ans,s);
    }
    else{
      d[r]=i;
      f(r+1,MIN(mt-p[i],t[i]));
    }
  }
}
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d %d %d",&p[i],&a[i],&w[i],&t[i]);
  f(0,1e9);
  printf("%d\n",ans);
  return 0;
}
