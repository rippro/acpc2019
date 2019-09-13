#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
vector<vector<int> > edge;

// ファイル名は prefix_num.in (ex: 00_sample_00.in)
void output(int N, int T, int S, int E, const string &prefix, int num){
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), num);
    ofstream ofs(name);
    ofs << N << " " << T << " " << S << " " << E << endl;
    rep(i, N-1) ofs << edge[i][0] << " " << edge[i][1] << " " << edge[i][2] << endl;
    ofs.close();
    edge.clear();
}

void make_graph(int N, int max_t = MAX_T){
    for (int i = 1; i < N; i++) {
        int initial, terminal, cost;
        initial = i + 1, terminal = rnd.next(1, i), cost = rnd.next(MIN_T, max_t);
        int random = rnd.next(1, 100000);
        if (random % 2 == 0) swap(initial, terminal);
        vector<int> in{initial, terminal, cost};
        edge.push_back(in);
        //edge[0].push_back(initial), edge[1].push_back(terminal), edge[2].push_back(cost);
    }
    shuffle(edge.begin(),edge.end());
}

void case_50_small(){
    for (int k = 1; k <= 10; k++) {
        int N = rnd.next(MIN_N, 10);
        int T = rnd.next(MIN_T, 100);
        int S = rnd.next(1, N), E = rnd.next(1, N);
        make_graph(N, 100);
        output(N, T, S, E, "50_small", k);
    }
}

void case_51_large(){
    for (int k = 1; k <= 15; k++) {
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S = rnd.next(1, N), E = rnd.next(1, N);
        make_graph(N);
        output(N, T, S, E, "51_large", k);
    }
}

void case_52_min(){
    int N = MIN_N;
    for(int k = 1; k < 5; k++){
        int T = rnd.next(MIN_T, MAX_T);
        int S = rnd.next(1, N), E = rnd.next(1, N);
        make_graph(N);
        output(N, T, S, E, "52_min", k);
    }
}

void case_53_max(){
    for(int k = 1; k <= 15; k++){
        int N = MAX_N;
        int T = MAX_T;
        int S = rnd.next(1, N), E = rnd.next(1, N);
        make_graph(N);
        output(N, T, S, E, "53_max", k);
    }
}

int make_shuffle(int n){
    vector<int> v;
    rep(i,n)v.push_back(i);
    shuffle(v.begin(),v.end());
    rep(i,n-1){
        edge[i][0] = v[edge[i][0] - 1] + 1;
        edge[i][1] = v[edge[i][1] - 1] + 1;
    }
    return v.back();
}

void case_54_path(){
    for(int k = 1; k <= 10; k++){
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S = rnd.next(1, N), E = rnd.next(1, N);
        rep(i,N-1){
            int cost = rnd.next(MIN_T, MAX_T);
            vector<int> in{i+1, i+2, cost};
            edge.push_back(in);
        }
        make_shuffle(N);
        output(N, T, S, E, "54_path", k);
    }
}

void case_55_star(){
    for(int k = 1; k <= 2; k++){//S中心 E中心
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S, E;
        rep(i,N-1){
            int cost = rnd.next(MIN_T, MAX_T);
            vector<int> in{i+1, N, cost};
            edge.push_back(in);
        }
        S = E = make_shuffle(N);//中心
        output(N, T, S, E, "55_star", k);
    }
    for(int k = 3; k <= 4; k++){//S中心 E外
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S, E = rnd.next(1, N);
        rep(i,N-1){
            int cost = rnd.next(MIN_T, MAX_T);
            vector<int> in{i+1, N, cost};
            edge.push_back(in);
        }
        S = make_shuffle(N);
        while(S == E) E = rnd.next(1, N);
        output(N, T, S, E, "55_star", k);
    }
    for(int k = 5; k <= 6; k++){//S外 E中心
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S = rnd.next(1, N), E;
        rep(i,N-1){
            int cost = rnd.next(MIN_T, MAX_T);
            vector<int> in{i+1, N, cost};
            edge.push_back(in);
        }
        E = make_shuffle(N);
        while(S == E) S = rnd.next(1, N);
        output(N, T, S, E, "55_star", k);
    }
    for(int k = 7; k <= 10; k++){//ランダム
        int N = rnd.next(MIN_N, MAX_N);
        int T = rnd.next(MIN_T, MAX_T);
        int S = rnd.next(1, N), E = rnd.next(1, N);
        rep(i,N-1){
            int cost = rnd.next(MIN_T, MAX_T);
            vector<int> in{i+1, N, cost};
            edge.push_back(in);
        }
        make_shuffle(N);
        output(N, T, S, E, "55_star", k);
    }
}
void challenge00(){
  int N=MAX_N,T=MIN_T;
  int S=1,E=N,i;
  for(i=0;i<N-1;i++){
    if(rnd.next(0,1)){
      vector<int> in{i+1,i+2,MAX_T};
      edge.push_back(in);
    }
    else{
      vector<int> in{i+2,i+1,MAX_T};
      edge.push_back(in);
    }
  }
  //make_shaffle(N-1);
  output(N,T,S,E,"60_challenge",0);    
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
    case_54_path();
    case_55_star();
    challenge00();
    return 0;
}
