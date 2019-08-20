#include "./testlib.h"
#include "./constraints.hpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
    registerValidation();

    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    while(n--){
        string s = inf.readToken();
        assert(MIN_SI <= s.size() && s.size() <= MAX_SI);
        for(auto &c : s) assert(isupper(c));
        inf.readEoln();
    }
    inf.readEof();
}
