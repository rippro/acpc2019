#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

signed main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m, 0));
    for(int i{}; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        --a;--b;
        d[a][b]++;
        d[b][a]++;
    }
    for(int i{}; i < n; ++i)
    {
        set<int> z;        
        for(int j{}; j < d[i].size(); ++j)
        {
            if(d[i][j] > 0)
            {
                z.insert(i+1);
                z.insert(j+1);
            }
        }
        for(auto const &k: z)
        {
            cout << k << ' ';
        }
        cout << '\n';
    }

}