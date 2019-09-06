#include<iostream>
#include<string>
using namespace std;
int main(){
    int x, t, s;
    cin >> x >> t >> s;
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(str == "nobiro"){
            x += t;
        }
        if(str == "tidime"){
            x += s;
        }
        if(str == "karero"){
            x = 0;
        }
        if(x < 0) x = 0;
    }
    cout << x << endl;
}
