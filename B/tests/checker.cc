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

    // 入力ファイルの読み込み testcaseの入力
    int n = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();
    string s = inf.readLine();
    inf.readEoln();
    inf.readEof();

    #ifdef RIME
        // デバッグ出力
        cout<<"debug output: ";
        cout << n << ' ' << s << endl;
    #endif

    // 解答による出力ファイルを読み込み(提出されてたファイル)
    int out_n = ouf.readInt(0, MAX_N);
    ouf.readEoln();
    string out_s;
    if(out_n > 0)out_s = ouf.readLine();
    ouf.readEoln();
    ouf.readEof();

    #ifdef RIME
        // デバッグ出力
        cout<<"debug output: ここまで完了";
    #endif

    // 正答ファイルを読み込み
    // 不要だがEOFまで読み込んでないとエラーになるので読み飛ばす
    // diff file
    int diff_n = ans.readInt(0,MAX_N);
    while(!ans.seekEof()) ans.readChar();

#ifdef RIME
    // デバッグ出力
    cout<<"debug output: ";
    cout << out_n << ' ' << out_s << ' ' << n << ' ' << s << endl;
#endif
    if(out_n != (int)(out_s.size())){
      WA();
      return 0;
    }
    if(out_n == 0 && diff_n == 0){
      AC();
      return 0;
    }

    // 判定
    if(out_n == diff_n){
      int x=0,y=0,out_x=0,out_y=0;
      for(int i=0;i<n;i++){
        if('A'<=s[i]&&s[i]<='M')y++;
        if('N'<=s[i]&&s[i]<='Z')y--;
        if('a'<=s[i]&&s[i]<='m')x++;
        if('n'<=s[i]&&s[i]<='z')x--;
      }

      for(int i=0;i<out_n;i++){
        if('A'<=out_s[i]&&out_s[i]<='M')out_y++;
        if('N'<=out_s[i]&&out_s[i]<='Z')out_y--;
        if('a'<=out_s[i]&&out_s[i]<='m')out_x++;
        if('n'<=out_s[i]&&out_s[i]<='z')out_x--;
      }
      if( y == out_y && x == out_x)AC();
      else WA();
    }
    else WA();
}
