#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

signed main()
{
    int n, m; cin >> n >> m;
    vector<pi> p;
    for(int i{}; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        //--a;--b;
        if(a > b) swap(a,b);

        p.emplace_back(a,b);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());    

    int prev{};
    for(int i{}; i < n; ++i)
    {
        if(prev+1 == p[i].first) cout << prev+1 << ' ';
        if(p[i].first == prev)
        {
            cout << p[i].second << ' ';
        }


        prev = p[i].first;        
    }
}