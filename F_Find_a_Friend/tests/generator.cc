#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
int a[MAX_M],b[MAX_M],c[MAX_M];
void output(int n, int m, int t, const string &prefix, int num){
    int flag[MAX_N+1] = {};
    int room_num = 0;
    rep(i,m){
        a[i] = rnd.next(MIN_A, t);
        b[i] = rnd.next(MIN_B,n);
        while(flag[b[i]] == 0 && room_num == 100)b[i] = rnd.next(MIN_B,n);
        c[i] = flag[b[i]] == 0;
        if(c[i])room_num++;
        else room_num--;
        flag[b[i]] = 1 - flag[b[i]];
    }
    sort(a,a+m);
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), num);
    ofstream ofs(name);
    ofs << n << " " << m << " " << t << endl;
    rep(i,m) ofs << a[i] << " " << b[i] << " " << c[i] << endl;
    ofs.close();
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());


    for(int i = 0; i < 10; ++i){
        int n = rnd.next(MIN_N, 10);
        int m = rnd.next(MIN_M, 10);
        int t = rnd.next(MIN_T, 100);
        output(n, m, t, "50_small", i);
    }
    for(int i = 0; i < 10; ++i){
        int n = rnd.next(MIN_N, MAX_N);
        int m = rnd.next(MIN_M, MAX_M);
        int t = rnd.next(MIN_T, MAX_T);
        output(n, m, t, "51_large", i);
    }
    for(int i = 0; i < 3; ++i){
        int n = rnd.next(MIN_N, MIN_N);
        int m = rnd.next(MIN_M, MIN_M);
        int t = rnd.next(MIN_T, MIN_T);
        output(n, m, t, "52_min", i);
    }
    for(int i = 0; i < 7; ++i){
        int n = rnd.next(MAX_N, MAX_N);
        int m = rnd.next(MAX_M, MAX_M);
        int t = rnd.next(MAX_T, MAX_T);
        output(n, m, t, "53_max", i);
    }
}
