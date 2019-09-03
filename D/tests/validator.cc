#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>

int main(){
    registerValidation();
	int N = inf.readInt(MIN_N, MAX_N);
	inf.readSpace();
	int T = inf.readInt(MIN_T, MAX_T);
	inf.readSpace();
	int S = inf.readInt(1, N);
	inf.readSpace();
	int E = inf.readInt(1, N);
	inf.readEoln();

	for (int i = 0; i < N; i++) {
		int a = inf.readInt(1, N);
		inf.readSpace();
		int b = inf.readInt(1, N);
		inf.readSpace();
		int n = inf.readInt(MIN_T, MAX_T);
		inf.readEoln();
	}

	inf.readEof();
}
