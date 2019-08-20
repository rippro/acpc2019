#include<stdio.h>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
int d[100010][4];
int MIN(int a,int b){return a<b?a:b;}
void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
void out(int n,char *s){
  FILE *f;
  int i,j;
  f=fopen(s,"w");
  fprintf(f,"%d\n",n);
  for(i=0;i<n;i++)fprintf(f,"%d %d %d %d\n",d[i][0],d[i][1],d[i][2],d[i][3]);
  fclose(f);
}
void MakeNum(int n){
  int i;
  for(i=0;i<n;i++){
    d[i][0]=rnd.next(MIN_R,MAX_R);
    d[i][1]=rnd.next(MIN_A,MAX_A);
    d[i][2]=rnd.next(MIN_W,MAX_W);
    d[i][3]=rnd.next(MIN_T,MAX_T);
  }
}
int main(){
  int n,i;
  char s[100];
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<100;i++){
    n=rnd.next(MIN_N,8);
    sprintf(s,"50_random_small_%02d.in",i);
    MakeNum(n);
    out(n,s);
  }

  return 0;
}

