#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

/*CAUTION!!
case
3 2
1 3
2 3
のとき
1 2 3
1 2 3
1 2 3

つまり1 2が直接繋がってなくても同値にはなる
*/
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
            z.insert(i+1);
        }
        for(int k{}; k < z.size(); ++k)
        {
            auto itr = z.begin();
            advance(itr, k);
            cout << *itr;
            if(k != z.size()-1)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

}