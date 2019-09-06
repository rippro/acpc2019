#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int north = 0, east = 0;
    for(int i = 0; i < n; i++){
        if('A' <= s[i] && s[i] <= 'M'){
            north++;
        }
        if('N' <= s[i] && s[i] <= 'Z'){
            north--;
        }
        if('a' <= s[i] && s[i] <= 'm'){
            east++;
        }
        if('n' <= s[i] && s[i] <= 'z'){
            east--;
        }
    }
    cout << abs(north) + abs(east) << endl;
    if(north > 0){
        for(int i = 0; i < north; i++){
            cout << "A";
        }
    }
    if(north < 0){
        for(int i = 0; i < -north; i++){
            cout << "N";
        }
    }
    if(east > 0){
        for(int i = 0; i < east; i++){
            cout << "a";
        }
    }
    if(east < 0){
        for(int i = 0; i < -east; i++){
            cout << "n";
        }
    }
    cout << endl;
}
