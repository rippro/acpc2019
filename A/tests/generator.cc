#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

#define MIN_X 0
#define MAX_X 100

#define MIN_S -100
#define MAX_S 100

#define MIN_T -100
#define MAX_T 100

#define MIN_N 1
#define MAX_N 1000

#define MIN_Si 0
#define MAX_Si 2

// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
void output(int x, int t, int s, int n, vector<string> &si, const string &prefix, int num){
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), num);
    ofstream ofs(name);
    ofs << x << " " << t << " " << s << endl << n << endl;
    for(int i = 0; i < n; ++i) {
        ofs << si[i] << endl;
    }
    ofs.close();
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    // 乱数ケースを10個生成
    for(int i = 0; i < 10; ++i){
        int X = rnd.next(MIN_X, MAX_X);
        int S = rnd.next(MIN_S, MAX_S);
        int T = rnd.next(MIN_T, MAX_T);
        int N = rnd.next(MIN_N, MAX_N);
        
        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);
        for(int i = 0; i < N; ++i) {
            si[i] = voice[rnd.next(MIN_Si, MAX_Si)];
        }

        output(X, T, S, N, si, "50_random", i);
    }

    // 片方が大きいケースを生成
    // for(int i = 0; i < 10; ++i){
    //     int A = 1;
    //     int B = 1;
    //     while(0.5*A <= B && B <= 1.5*A){
    //         A = rnd.next(MIN_A, MAX_A);
    //         B = rnd.next(MIN_B, MAX_B);
    //     }
    //     if(rnd.next(0,1)) swap(A, B);
    //     output(A, B, "60_unbalance", i);
    // }
}
