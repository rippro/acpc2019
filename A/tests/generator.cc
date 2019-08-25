#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

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

    // 手計算できる程度(10ぐらい)に小さいランダムケース
    for(int i = 0; i < 10; ++i) {
        int X = rnd.next(MIN_X, 30);
        int S = rnd.next(MIN_S, 30);
        int T = rnd.next(MIN_T, 30);
        int N = rnd.next(MIN_N, 20);
        
        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);
        for(int j = 0; j < N; ++j) {
            si[j] = voice[rnd.next(MIN_Si, MAX_Si)];
        }

        output(X, T, S, N, si, "50_small", i);
    }

    // 完全ランダム(最大ケースではない)
    for(int i = 0; i < 10; ++i){
        int X = rnd.next(MIN_X, MAX_X);
        int S = rnd.next(MIN_S, MAX_S);
        int T = rnd.next(MIN_T, MAX_T);
        int N = rnd.next(MIN_N, MAX_N);
        
        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);
        for(int j = 0; j < N; ++j) {
            si[j] = voice[rnd.next(MIN_Si, MAX_Si)];
        }

        output(X, T, S, N, si, "51_large", i);
    }

    // 最小ケース
    {
        int X = rnd.next(MIN_X, MAX_X);
        int S = rnd.next(MIN_S, MAX_S);
        int T = rnd.next(MIN_T, MAX_T);
        int N = 1;
        
        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(1);
        
        si[0] = voice[rnd.next(MIN_Si, MAX_Si)];

        output(X, T, S, N, si, "52_min", 0);
    }

    // 最大ケース
    {
        int X = 100;
        int S = 100;
        int T = 100;
        int N = 1000;
        
        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);
        for(int j = 0; j < N; ++j) {
            si[j] = voice[rnd.next(MIN_Si, MAX_Si)];
        }

        output(X, T, S, N, si, "53_max", 0);
    }

    // コーナーケース
    {//めっちゃ植物が縮むケース
        int X = 0;
        int S = -100;
        int T = -100;
        int N = 1000;

        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);

        for(int j = 0; j < N; ++j) {
            si[j] = voice[rnd.next(MIN_Si, MAX_Si)];
        }

        output(X, T, S, N, si, "60_challenge", 0);
    }
    {//植物がずっと枯れているケース
        int X = 100;
        int S = 0;
        int T = 0;
        int N = 1000;

        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);

        for(int j = 0; j < N; ++j) {
            si[j] = voice[2];
        }

        output(X, T, S, N, si, "60_challenge", 1);
    }
    {//制約が全て0のケース
        int X = 0;
        int S = 0;
        int T = 0;
        int N = 1;

        string voice[3] = {"nobiro", "tidime", "karero"};
        vector<string> si(N);

        for(int j = 0; j < N; ++j) {
            si[j] = voice[rnd.next(MIN_Si, MAX_Si)];
        }

        output(X, T, S, N, si, "60_challenge", 2);
    }
}
