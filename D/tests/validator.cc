#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <vector>
using namespace std;

bool isTree(vector<vector<int>>& g, int cur, int pre, vector<bool>& used){
	used[cur] = true;

	bool res = true;
	for(auto to : g[cur]){
		if(to == pre) continue;
		if(used[to]) return false; // $BJ?O)$r8!=P$7$?>l9g(B false $B$rJV$9(B
		res |= isTree(g, to, cur, used);
	}
	return res;
}

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

	vector<vector<int>> g(N);
	for (int i = 1; i < N; i++) {
		int a = inf.readInt(1, N);
		inf.readSpace();
		int b = inf.readInt(1, N);
		inf.readSpace();
		int n = inf.readInt(MIN_W, MAX_W);
		inf.readEoln();

		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<bool> used(N, false);
	assert(isTree(g, 0, -1, used));

	inf.readEof();
}
