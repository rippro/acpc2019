#include<stdio.h>
int cc[100010],o[100010],ta[100010],to[200010],nt[200010],co[200010],S,T;
int R=1,C=1,H[2000010],N[2000010];
//評価関数（いまはMAX）
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
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
int d[100010],r=0,t[100010];
int f(int s,int p){//printf("%d %d\n",s,p);
  int i,j,a=0,br=r,e=2;
  if(s-S)e++;
  R=C=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(to[i]==p)continue;
    t[R]=i;
    hin(co[i]);
  }
  while(C-1)d[r++]=t[hout()];
  for(j=0;j<cc[s];j++){
    i=d[br+j];
    if(f(to[i],s)==0)return 0;
    a=co[i]-cc[to[i]];
    if(o[to[i]]){
      o[s]=1;
      if(a<1)return 0;
    }
    else{
      if(a<2+(s!=S?1:0))return 0;
      if(a<e)return 0;
      e++;
    }
  }//printf("s%d:",s);
  
  return 1;
}
int main(){
  int n,m,i,a,b,c;
  scanf("%d %d %d %d",&n,&m,&S,&T);
  for(i=0;i<n;i++)ta[i+1]=-1;
  for(i=0;i<n-1;i++){
    scanf("%d %d %d",&a,&b,&c);
    nt[i    ]=ta[to[i+n-1]=a];
    nt[i+n-1]=ta[to[i    ]=b];
    co[ta[b]=i+n-1]=co[ta[a]=i]=(c-1)/m+1;
    cc[a]++;
    cc[b]++;
  }
  for(i=1;i<=n;i++){
    if(i==T)continue;
    cc[i]--;
  }
  o[S]=1;
  printf("%s\n",f(T,T)?"Yes":"No");
  return 0;
}
