#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
vector<int> a, b, w;

// ファイル名は prefix_num.in (ex: 00_sample_00.in)
void output(int N, int T, int S, int E, vector<int> a, vector<int> b, vector<int> w, const string &prefix, int num){
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), num);
    ofstream ofs(name);
    ofs << N << " " << T << " " << S << " " << E << endl;
    rep(i, N) ofs << a[i] << " " << b[i] << " " << w[i] << endl;
    ofs.close();
}

void make_graph(int N){
    for (int i = 1; i <= N; i++) {
        int initial, terminal, cost;
        initial = i + 1, terminal = rnd.next(1, i), cost = rnd.next(1, 100);
        int random = rnd.next(1, 100000);
        if (random % 3 == 0) swap(initial, terminal);
        a.push_back(initial), b.push_back(terminal), w.push_back(cost);
    }
}

void case_50_small(){
    for (int k = 1; k <= 10; k++) {
        int N = rnd.next(MIN_N, 10);
        int T = rnd.next(MIN_T, 100);
        int S = rnd.next(MIN_N, N), E = rnd.next(MIN_N, N);
        make_graph(N);
        output(N, T, S, E, a, b, w, "50_small", k);
        a.empty(), b.empty(), w.empty();
    }
}

void case_51_large(){
    for (int k = 1; k <= 15; k++) {
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S = rnd.next(MIN_N, N), E = rnd.next(MIN_N, N);
        make_graph(N);
        output(N, T, S, E, a, b, w, "51_large", k);
        a.empty(), b.empty(), w.empty();
    }
}

void case_52_min(){
    int N = MIN_N;
    int T = MIN_T;
    int S = MIN_N, E = MIN_N;
    vector<int> a(N), b(N), w(N);
    a[0] = 1, b[0] = 1, w[0] = 1;
    output(N, T, S, E, a, b, w, "52_min", 1);
}

void case_53_max(){
    for(int k = 1; k <= 15; k++){
        int N = MAX_N;
        int T = MAX_T;
        int S = rnd.next(MIN_N, N), E = rnd.next(MIN_N, N);
        make_graph(N);
        output(N, T, S, E, a, b, w, "53_max", k);
        a.empty(), b.empty(), w.empty();
    }
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());
    // 乱数ケースを10個生成
    case_50_small();
    case_51_large();
    case_52_min();
    case_53_max();
    return 0;
}
