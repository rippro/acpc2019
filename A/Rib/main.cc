#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main()
{
    int x,t,s; cin >> x >> t >> s;
    int n; cin >> n;
    for(int i{}; i < n; ++i)
    {
        string ss; cin >> ss;
        if     (ss == "nobiro") x = max(x+t, 0);
        else if(ss == "tidime") x = max(x+s, 0);
        else if(ss == "karero") x = 0;
    }

    cout << x << '\n';
}
