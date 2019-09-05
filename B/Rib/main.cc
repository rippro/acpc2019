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
    int north{}, south{}, east{}, west{};
    for (auto &i : s)
    {
        if     ('A' <= i && i <= 'M') ++north;
        else if('N' <= i && i <= 'Z') ++south;
        else if('a' <= i && i <= 'm') ++east;
        else if('n' <= i && i <= 'z') ++west;
    }
    cout << abs(north-south+east-west) << '\n';
    
    for(int i{}; i < north-south; ++i) cout << 'A';
    for(int i{}; i < south-north; ++i) cout << 'N';
    for(int i{}; i < east-west; ++i)   cout << 'a';
    for(int i{}; i < west-east; ++i)   cout << 'n';

    cout << '\n';
}