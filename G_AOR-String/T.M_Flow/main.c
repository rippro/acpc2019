#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
int ta[1010],to[1000010],nt[1000010],co[1000010],F[1010];
int MF(int s,int t,int e,int min){
  if(s==t||min==0)return min;
  int i,r;
  F[s]=1;
  for(i=ta[s];i+1;i=nt[i]){
    if(F[to[i]])continue;//printf("%d %d\n",s,to[i]);
    r=MF(to[i],t,e,MIN(min,co[i]));
    co[i]-=r;
    co[(i+e)%(2*e)]+=r;
    if(r)return r;
  }
  return 0;
}
int maxf(int s,int t,int v,int e){
  int i,f,r;
  for(i=0;i<v;i++)F[i]=0;
  for(f=0;r=MF(s,t,e,1000000000);f+=r){
    for(i=0;i<v;i++)F[i]=0;
  }
  return f;
}
void mkls(int v,int e,int *a,int *b,int *c){
  int i;
  for(i=0;i<v;i++)ta[i]=-1;
  for(i=0;i<e;i++){
    nt[i  ]=ta[to[i+e]=a[i]];
    nt[i+e]=ta[to[i  ]=b[i]];
    co[ta[a[i]]=i  ]=c[i];
    co[ta[b[i]]=i+e]=0;
  }
}
int main(){
  int n,i,min,ans=0,o=0,d[3][3]={0};
  int r=0,a[1010],b[1010],c[1010],f,t;
  //*-*,*-A,*-AO,R-*,R-A,R-AO,OR-*,OR-A,OR-AO
  char s[1010];
  scanf("%d",&n);
  for(r=n;r;r--){
    scanf("%s",s);
    if(s[1]==0){
      if     (s[0]=='A')d[0][1]++;
      else if(s[0]=='O')o++;
      else if(s[0]=='R')d[1][0]++;
      else              d[0][0]++;
      continue;
    }
    f=t=0;
    if(s[0]=='R')f=1;
    if(s[0]=='O'&&s[1]=='R')f=2;
    for(i=0;s[i+2];i++){
      if(s[i]=='A'&&s[i+1]=='O'&&s[i+2]=='R')ans++;
    }
    if(s[i+1]=='A')t=1;
    if(s[i]=='A'&&s[i+1]=='O')t=2;
    d[f][t]++;
  }
  if(d[1][1]&&d[1][1]==d[2][2]&&n==d[0][0]+d[1][1]+d[2][2]+o)ans--;
  for(i=1;i<9;i++){
    a[r  ]=0;
    b[r  ]=i;
    c[r++]=d[i/3][i%3];
  }
  for(i=1;i<9;i++){
    a[r  ]=i+9;
    b[r  ]=9;
    c[r++]=d[i/3][i%3];
  }
  for(i=0;i<64;i++){
    f=i/8+1;
    t=i%8+1;
    if(f%3+t/3==3){
      a[r  ]=f;
      b[r  ]=t+9;
      c[r++]=(f==t?MAX(0,d[f/3][f%3]-1):MIN(d[f/3][f%3],d[t/3][t%3]));
    }
  }
  for(i=0;i<3;i++){
    f=i*3+1;
    t=i  +3+9;
    a[r  ]=f;
    b[r  ]=18;
    c[r++]=d[i][1];
    a[r  ]=19;
    b[r  ]=t;
    c[r++]=d[1][i];
  }
  a[r  ]=18;
  b[r  ]=19;
  c[r++]=0;
  mkls(20,r,a,b,c);
  ans+=maxf(0,9,20,r);
  co[r-1]=o;
  f=co[0]+co[6]+co[10]+co[12];
  ans+=maxf(0,9,20,r);
  if(co[36]+co[37]==0&&co[36+r]&&(f)==0)ans--;
  printf("%d\n",ans);
  return 0;
}
//A,ORAO,RA,ORAO,RAO,RA
