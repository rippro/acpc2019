#include <bits/stdc++.h>
using namespace std;

//ワーフロ
signed main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(n, 1));
    for(int i{}; i < n; ++i)
    for(int j{}; j < n; ++j)d[i][i]=0;

    for(int i{}; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        d[--a][--b]=0;//塗る    
    }

    for(int k{}; k < n; ++k)
    for(int i{}; i < n; ++i)
    for(int j{}; j < n; ++j)
    {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }

    for(int i{}; i < n; ++i)
    {
        bool flag = false;
        for(int j{}; j < n; ++j)
        {
            if(d[i][j]==0)
            {
                if(flag)
                cout << ' ';
                cout << j+1;
                flag = true;
            }
        }
        cout << '\n';
    }
}