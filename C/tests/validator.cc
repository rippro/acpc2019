#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>

#define MIN_A 1

#define MIN_B 1

int main(){
    registerValidation();
    int n = inf.readInt(MIN_N, MAX_N);
    inf.readSpace();

    int m = inf.readInt(MIN_M, n*(n - 1));
    inf.readEoln();
    
    bool flag = true;

    for(int i = 0; i < m; ++i) {
        int a = inf.readInt(MIN_A, n);
        inf.readSpace();
        int b = inf.readInt(MIN_B, n);
        inf.readEoln();
        
        if(a == b) {
            flag = false;
            assert(flag);
        }
    }

    inf.readEof();
}
