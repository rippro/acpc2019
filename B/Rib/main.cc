#include<bits/stdc++.h>
using namespace std;
//#define int long long



signed main()
{
    int n; cin >> n;
    string s; cin >> s;
    /*
           north(y+=1)
            ↑
west(x-=1)←　→east(x+=1)
            ↓
           south(y-=1)
    */
    int x{}, y{}; 
    for (auto &i : s)
    {
        if     ('A' <= i && i <= 'M') ++y;
        else if('N' <= i && i <= 'Z') --y;
        else if('a' <= i && i <= 'm') ++x;
        else if('n' <= i && i <= 'z') --x;
    }
    cout << abs(x)+abs(y) << '\n';
    
    for(int i{}; i < y; ++i) cout << 'A';
    for(int i{}; i < -y; ++i) cout << 'N';
    for(int i{}; i < x; ++i)   cout << 'a';
    for(int i{}; i < -x; ++i)   cout << 'n';

    cout << '\n';
}