#include <cassert>
#include "./testlib.h"
#include "./constraints.hpp"
#include <assert.h>
using namespace std;

int main(){
    registerValidation();
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    string s = inf.readString();
    //inf.readEoln();
    for (int i = 0; i < N; i++){
        bool flag = false;
        for(char c = 'a'; c <= 'z'; c++) if(s[i] == c) flag = true;
        for(char c = 'A'; c <= 'Z'; c++) if(s[i] == c) flag = true;
        assert(flag);
    }
    inf.readEof();
}
