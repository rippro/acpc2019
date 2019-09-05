#include<bits/stdc++.h>
using namespace std;
//#define int long long



signed main()
{
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp;
    for(int i{}; i < (int)s.size(); ++i)
    {
        mp[s[i]]++;
    }
    int north{};
    int west{};
    int east{};
    int south{};
    for(auto a: mp)
    {
        const char b = a.first;
        if(b=='A'||b=='B'||b=='C'||b=='D'||b=='E'||b=='F'
         ||b=='G'||b=='H'||b=='I'||b=='J'||b=='K'||b=='L'||b=='M')
        {
             ++north;
        }
        else if(b=='N'||b=='O'||b=='P'||b=='Q'||b=='R'||b=='S'
               ||b=='T'||b=='U'||b=='V'||b=='W'||b=='X'||b=='Y'||b=='Z')
        {
            ++south;
        }
        else if(b=='a'||b=='b'||b=='c'||b=='d'||b=='e'||b=='f'
              ||b=='g'||b=='h'||b=='i'||b=='j'||b=='k'||b=='l'||b=='m')
        {
            ++east;
        }
        else
        {
            ++west;
        }
    }
    int sum = north+south+east+west;
    cout << sum << '\n';
    for(int i = 0; i < north; ++i)
        cout << 'A';
    for(int i = 0; i < south; ++i)
        cout << 'N';
    for(int i = 0; i < east; ++i)
        cout << 'a';
    for(int i = 0; i < west; ++i)
        cout << 'n';
    
}