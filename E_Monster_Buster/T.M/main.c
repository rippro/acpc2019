#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
int MAX(int a,int b){return a<b?b:a;}
//評価関数（いまはMIN）
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]>N[H[b]]?1:0;
}
//挿入関数
void hin(int a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//取り出す関数
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int main(){
  int n,r[100010],t[100010],p[100010],w[100010],i,j,m,d[2][100010]={};
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d %d %d",&r[i],&p[i],&w[i],&t[i]);
    hin(r[i]+t[i]);
  }
  for(i=0;i<4010;i++)d[1][i]=-1e9;
  while(C-1){
    m=hout()-1;
    for(i=N[m+1];i>=r[m];i--){
      d[0][i]=MAX(d[0][i],d[0][i+1]);
      d[1][i]=MAX(d[1][i],d[1][i+1]);
      d[1][i-r[m]]=MAX(d[1][i-r[m]],MAX(d[0][i]+p[m],d[1][i]+w[m]));
    }
    for(i=N[m+1];i;i--){
      d[0][i]=MAX(d[0][i],d[1][i]);
      d[1][i]=-1e9;
    }
  }
  printf("%d\n",d[0][1]);
  return 0;
}
