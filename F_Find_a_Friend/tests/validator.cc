#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	registerValidation();
	int N = inf.readInt(MIN_N, MAX_N);
	inf.readSpace();
	int M = inf.readInt(MIN_M, MAX_M);
	inf.readSpace();
	int T = inf.readInt(MIN_T, MAX_T);
	inf.readEoln();

	vector<tuple<int,int,int>> m(M);
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int A = inf.readInt(MIN_A, MAX_A);
		inf.readSpace();
		int B = inf.readInt(MIN_B, MAX_B);
		inf.readSpace();
		int C = inf.readInt(MIN_C, MAX_C);
		inf.readEoln();

		B--; // 0-index
		m[i] = make_tuple(A, B, C);
	}
	inf.readEof();

	int count = 0;
	vector<bool> exist(N, false);
	int pre_time = -1;
	for(auto t : m){
		int time, num, in;
		tie(time, num, in) = t;

		assert(pre_time <= time);
		pre_time = time;

		if(in){ // 入室
			count++;
			assert(!exist[num]);
			exist[num] = true;
		}else{ // 退室
			count--;
			assert(exist[num]);
			exist[num] = false;
		}
		assert(count >= 0 and count <= 100);
	}

}
