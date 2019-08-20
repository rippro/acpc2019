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

    rep(case_num,10){   //ランダムケース(large)
        char file_name[100];
        int N = rnd.next(MIN_N,(int)(MAX_N/3));

        vector<string> vs;
        rep(i,N){
            //95% [AOR] , 5% [A-Z]
            vs.push_back( rnd.next("[AORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORA-Z]{%d,%d}",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"11-randomLarge-%02d.in",case_num);
        output(N,vs,file_name);
    }

    rep(case_num,1000){   //ランダムケース(small)
        char file_name[100];
        int N = rnd.next(MIN_N,MAX_N);

        vector<string> vs;
        rep(i,N){
            //95% [AOR] , 5% [A-Z]
            vs.push_back( rnd.next("[AORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORAORA-Z]{%d,%d}",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"11-randomSmall-%02d.in",case_num);
        output(N,vs,file_name);
    }


    rep(case_num,20){   //文字列がA,O,Rのみからなるケース
        char file_name[100];
        int N = rnd.next(MIN_N,MAX_N);

        vector<string> vs;
        rep(i,N){
            vs.push_back( rnd.next("[AOR]{%d,%d}",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"12-onlyAOR-%02d.in",case_num);
        output(N,vs,file_name);
    }


    rep(case_num,10){   //文字列がA,O,Rのみからなり、s_i = "O" を多く含むケース
        char file_name[100];
        int N = rnd.next(MIN_N,MAX_N);

        vector<string> vs;
        rep(i,N){
            vs.push_back( rnd.next("( O | [AOR]{%d,%d} )",MIN_SI,MAX_SI) );
        }
        sprintf(file_name,"13-manyO-%02d.in",case_num);
        output(N,vs,file_name);
    }

}
