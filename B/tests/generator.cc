#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

// Nをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
void output(int N, const string &prefix, int i){
    char name[100];
    //rep回すのめんどくさかったんで
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    sprintf(name, "%s_%02d.in", prefix.c_str(), i);
    ofstream ofs(name);
    ofs << N << endl;
    for(int j = 0; j < N; ++j){
        int whichmoji = rnd.next(0, 51);
        ofs << a[whichmoji];
    }
    ofs << endl;
    ofs.close();
}
/*
void output2(int N, const string &prefix, int i){
    char name[100];
    //rep回すのめんどくさかったんで
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    sprintf(name, "%s_%02d.in", prefix.c_str(), i);
    ofstream ofs(name);
    ofs << N << endl;
    for(int j = 0; j < N; ++j){
        int whichmoji = (j&1);
        ofs << a[whichmoji];
    }
    ofs << endl;
    ofs.close();
}*/


/*
　→→→
　↑　↓
　↑　↓
　←←←
これ以外になるときansmax
*/
/*
void output3(int N, const string &prefix, int i){
    char name[100];
    //rep回すのめんどくさかったんで
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    sprintf(name, "%s_%02d.in", prefix.c_str(), i);
    ofstream ofs(name);
    ofs << N << endl;
    for(int j = 0; j < N; ++j){
        int whichmoji = j%52;
        ofs << a[whichmoji];
    }
    ofs << endl;
    ofs.close();
}*/

void case_50_small(){
    for(size_t i = 0; i < 10; ++i){
        int strlengrh = rnd.next(MIN_N, 10);
        output(strlengrh, "50_small", i);
    }
}

void case_51_large(){
    for(size_t i = 0; i < 10; ++i){
        int strlengrh = rnd.next(MIN_N, MAX_N);
        output(strlengrh, "51_large", i);
    }
}

void case_52_nmin(){
    //10 testcases.
    for(size_t i = 0; i < 10; ++i){
        int strlengrh = MIN_N;
        output(strlengrh, "52_nmin", i);
    }
}

void case_53_nmax(){
    //10 testcases.
    for(size_t i = 0; i < 10; ++i){
        int strlengrh = MAX_N;
        output(strlengrh, "53_nmax", i);
    }
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    case_50_small();
    case_51_large();
    case_52_nmin();
    case_53_nmax();
}
/*
    // 乱数ケースを10個生成
    for(int i = 0; i < 10; ++i){
        int N = rnd.next(MIN_N, MAX_N);
        output(N, "50_random", i);
    }
*/