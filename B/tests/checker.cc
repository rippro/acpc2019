#include "./testlib.h"
#include "./constraints.hpp"
#include <cassert>
#include <iostream>
#include <string>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

// AOJとRimeではスペシャルジャッジ用チェッカーの仕様が違う。
// - AOJでは何も出力せずに正常終了するとAC、何か出力して正常終了するとWA
//   (異常終了してはいけない)
// - Rimeでは正常終了するとAC、異常終了するとWA
// 
// これを切り替えるため、Rimeでテストするときには #define RIME する
// ソースコードに埋め込むと都合が悪いので、コンパイルオプションに設定する
// g++ checker -D RIME
// 設定方法はTESTSETを参照
// AOJに提出するときは下の行を消す
// #define RIME

void WA(){
#ifdef RIME
    quit(_wa, "Wrong Answer");
#else // AOJ
    cout << "WA" << endl;
    exit(0);
#endif
}

void AC(){
#ifdef RIME // AOJ
    quit(_ok, "Accepted");
#else // AOJ
    exit(0);
#endif
}

int main(int argc, char *argv[]) {
    // スペシャルジャッジでもtestlibを使える

    // Rimeでは
    // ./checker --infile $judgein --difffile $judgeout --outfile $userout
    // と実行される
    // AOJでは
    // ./checker $judgein $userout $judgeout > diff_log
    // と実行される
    // testlibを使うときはこの違いを吸収しないといけない
    
    // checker   : 判定プログラム
    // $judgein  : 入力ファイル
    // $userout  : ユーザが提出したコードによる出力
    // $judgeout : ジャッジが用意した出力
    // diff_log  : checkerによる出力

#ifdef RIME
    // testlibと違うので合わせる
    assert(argc == 7);
    int argc_mod = 4;
    char *argv_mod[4];
    argv_mod[0] = argv[0];
    for(int i = 1; i < argc; ++i){
        if(strcmp(argv[i], "--infile") == 0){
            argv_mod[1] = argv[++i];
        } else if(strcmp(argv[i], "--difffile") == 0){
            argv_mod[3] = argv[++i];
        } else if(strcmp(argv[i], "--outfile") == 0){
            argv_mod[2] = argv[++i];
        }
    }
    registerTestlibCmd(argc_mod, argv_mod);
#else // AOJ
    // testlibと同じなのでそのまま渡す
    registerTestlibCmd(argc, argv);
#endif

    // 入力ファイルの読み込み
    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    inf.readEof();

    // 解答による出力ファイルを読み込み
    int a = ouf.readInt(MIN_A, MAX_A);
    ouf.readSpace();
    int b = ouf.readInt(MIN_A, MAX_A);
    ouf.readEoln();
    ouf.readEof();

    // 正答ファイルを読み込み
    // 不要だがEOFまで読み込んでないとエラーになるので読み飛ばす
    while(!ans.seekEof()) ans.readChar();

#ifdef RIME
    // デバッグ出力
    cout << a << ' ' << b << ' ' << n << endl;
#endif

    // 判定
    if(a + b == n) AC();
    else WA();
}
