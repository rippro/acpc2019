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

    rep(case_num,1000){   //ランダムケース(small)
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

}
