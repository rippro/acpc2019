#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

//長さnの文字列配列/vector ssをnameというファイルに出力
template<class T>
void output(int n, const T &ss, const string &name){
    ofstream ofs(name);
    ofs << n << '\n';
    rep(i,n) ofs << ss[i] << '\n';
    ofs.close();
}
void challenge(){
  int i,j,k,d[10],n=1,sum=0,m[9]={2,2,2,3,3,2,3,3,2};
  char name[100]={"60-challenge-XXXXXXXXX.in"};
  vector<string>s={"A","AO","R","RA","RAO","OR","ORA","ORAO","O"};
  for(i=0;i<9;i++)n*=m[i];
  for(i=1;i<n;i++){
    k=i;
    sum=0;
    for(j=9;j--;){
      d[j]=k%m[j];
      k/=m[j];
      sum+=d[j];
    }
    
    for(j=0;j<9;j++)name[j+13]=d[j]+'0';
    vector<string> vs;
    for(j=0;j<9;j++){
      for(k=0;k<d[j];k++)vs.push_back(s[j]);
    }
    output(sum,vs,name);
  }
}
int main(){
    rnd.setSeed(time(0)+getpid());
    
    rep(case_num,5){   //ランダムケース(small)
      char file_name[100];
      int N = rnd.next(MIN_N,8);

      vector<string> vs;
      rep(i,N){
	vs.push_back( rnd.next("[A-Z]{%d,%d}",MIN_SI,MAX_SI) );
      }
      sprintf(file_name,"50-randomSmall-%02d.in",case_num);
      output(N,vs,file_name);
    }
    
    rep(case_num,5){   //ランダムケース(large)
      char file_name[100];
      int N = rnd.next(MIN_N,MAX_N);

      vector<string> vs;
      rep(i,N){
	vs.push_back( rnd.next("[A-Z]{%d,%d}",MIN_SI,MAX_SI) );
      }
      sprintf(file_name,"51-randomLarge-%02d.in",case_num);
      output(N,vs,file_name);
    }

    rep(case_num,5){   //ランダムケース(MIN)
      char file_name[100];
      int N = MIN_N;

      vector<string> vs;
      rep(i,N){
	vs.push_back( rnd.next("[A-Z]{%d,%d}",MIN_SI,MAX_SI) );
      }
      sprintf(file_name,"52-randomMIN-%02d.in",case_num);
      output(N,vs,file_name);
    }
    
    rep(case_num,5){   //ランダムケース(MAX)
      char file_name[100];
      int N = MAX_N;

      vector<string> vs;
      rep(i,N){
	vs.push_back( rnd.next("[A-Z]{%d,%d}",MIN_SI,MAX_SI) );
      }
      sprintf(file_name,"53-randomMAX-%02d.in",case_num);
      output(N,vs,file_name);
    }
    
    rep(case_num,10){   //ランダムケース(large)
      char file_name[100];
        int N = rnd.next(MIN_N,MAX_N);

        vector<string> vs;
        rep(i,N){
            //95% [AOR] , 5% [A-Z]
            vs.push_back( rnd.next("[AORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORA-Z]{%d,%d}",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"55-randomLargeAOR-%02d.in",case_num);
        output(N,vs,file_name);
    }

    rep(case_num,100){   //ランダムケース(small)
        char file_name[100];
        int N = rnd.next(MIN_N,8);

        vector<string> vs;
        rep(i,N){
            //95% [AOR] , 5% [A-Z]
            vs.push_back( rnd.next("[AORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORA-Z]{%d,%d}",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"54-randomSmallAOR-%02d.in",case_num);
        output(N,vs,file_name);
    }


    rep(case_num,20){   //文字列がA,O,Rのみからなるケース
        char file_name[100];
        int N = rnd.next(MIN_N,MAX_N);

        vector<string> vs;
        rep(i,N){
            vs.push_back( rnd.next("[AOR]{%d,%d}",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"56-onlyAOR-%02d.in",case_num);
        output(N,vs,file_name);
    }


    rep(case_num,10){   //文字列がA,O,Rのみからなり、s_i = "O" を多く含むケース
        char file_name[100];
        int N = rnd.next(MIN_N,MAX_N);

        vector<string> vs;
        rep(i,N){
            vs.push_back( rnd.next("( O | [AOR]{%d,%d} )",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"57-manyO-%02d.in",case_num);
        output(N,vs,file_name);
    }
    challenge();
}
