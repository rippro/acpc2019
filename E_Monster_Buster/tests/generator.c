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
int main(){
  int n,i,j;
  char s[100];
  rnd.setSeed(time(0)+getpid());

  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,8);
    sprintf(s,"50_small_%02d.in",i);
    for(j=0;j<n;j++){
      d[j][0]=rnd.next(MIN_R,20);
      d[j][1]=rnd.next(0,20);
      d[j][2]=rnd.next(0,20);
      d[j][3]=rnd.next(MIN_T,20);
    }
    out(n,s);
  }
  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MAX_N);
    sprintf(s,"51_large_%02d.in",i);
    for(j=0;j<n;j++){
      d[j][0]=rnd.next(MIN_R,MAX_R);
      d[j][1]=rnd.next(MIN_A,MAX_A);
      d[j][2]=rnd.next(MIN_W,MAX_W);
      d[j][3]=rnd.next(MIN_T,MAX_T);
    }
    out(n,s);
  }
  for(i=0;i<10;i++){
    n=rnd.next(MIN_N,MIN_N);
    sprintf(s,"52_min_%02d.in",i);
    for(j=0;j<n;j++){
      d[j][0]=rnd.next(MIN_R,MAX_R);
      d[j][1]=rnd.next(MIN_A,MAX_A);
      d[j][2]=rnd.next(MIN_W,MAX_W);
      d[j][3]=rnd.next(MIN_T,MAX_T);
    }
    out(n,s);
  }
  for(i=0;i<10;i++){
    n=rnd.next(MAX_N,MAX_N);
    sprintf(s,"53_max_%02d.in",i);
    for(j=0;j<n;j++){
      d[j][0]=rnd.next(MIN_R,MAX_R);
      d[j][1]=rnd.next(MIN_A,MAX_A);
      d[j][2]=rnd.next(MIN_W,MAX_W);
      d[j][3]=rnd.next(MIN_T,MAX_T);
    }
    out(n,s);
  }

  return 0;
}
