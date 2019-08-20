#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
int main(){
  int i,j,x,y;
  registerValidation();
  // read first line
  int N = inf.readInt(MIN_N, MAX_N);
  inf.readEoln();
  for(i=0;i<N;i++){   
      inf.readInt(MIN_R, MAX_R);
      inf.readSpace();
      inf.readInt(MIN_A, MAX_A);
      inf.readSpace();
      inf.readInt(MIN_W, MAX_W);
      inf.readSpace();
      inf.readInt(MIN_T, MAX_T);
      inf.readEoln(); 
  }
  inf.readEof();
}
