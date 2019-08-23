#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include<assert.h>

int main(){
    registerValidation();
    inf.readInt(MIN_X, MAX_X);
    inf.readSpace();
    inf.readInt(MIN_T, MAX_T);
    inf.readSpace();
    inf.readInt(MIN_S, MAX_S);
    inf.readEoln();
    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    bool flag = true;
    for(int i = 0; i < n; ++i){
        std::string s = inf.readString();
        if(s != "nobiro" && s != "tidime" && s != "karero"){
            flag = false;
            assert(flag);
        }
        inf.readEoln();
    }
    inf.readEof();
}
