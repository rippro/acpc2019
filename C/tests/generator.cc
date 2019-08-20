#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <iomanip>
#include <sys/types.h>
#include <unistd.h>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

// ファイル名は prefix_num.in (ex: 00_sample_00.in)

void output(const int N, const int M, const string &prefix,
            const int num = 0) {
  ostringstream os;
  os << prefix << '_' << setw(2) << setfill('0') << num << ".in";
  ofstream ofs(os.str());
  ofs << N << ' '<< M << '\n';
  set<pair<int,int>> st;
  rep(i, M) {
    int a, b;
    while(1){
      a = rnd.next(1, N);
      b = rnd.next(1, N);
      if(a != b && !st.count(make_pair(a,b))){
        st.insert(make_pair(a,b));
        break;
      }
    }
    ofs << a << ' '<< b << "\n";
  }
  ofs.close();
}

void case_50_small() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, 10);
    int M = rnd.next(MIN_M,MAX_M);
    output(N, M, "50_small", num);
  }
}

void case_51_large() {
  rep(num, 10) {
    int N = rnd.next(MIN_N, MAX_N);
    int M = rnd.next(MIN_M,MAX_M);
    output(N, M, "51_large", num);
  }
}

void case_52_Nmin() {
  rep(num, 10) {
    int N = MIN_N;
    int M = N*(N-1);
    output(N, M, "52_Nmin", num);
  }
}

void case_53_Nmax() {
  rep(num, 10) {
    int N = MAX_N;
    int M = rnd.next(MIN_M,MAX_M);
    output(N, M, "53_Nmax", num);
  }
}

int main(){
    rnd.setSeed(time(nullptr)+getpid());

    case_50_small();
    case_51_large();
    case_52_Nmin(); //これ全部一緒だけどいるのか？
    case_53_Nmax();


}
