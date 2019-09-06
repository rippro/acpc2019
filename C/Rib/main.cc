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

/*
last
o1,1 o1,2 o1,3
o2,1 o2,2 o2,3
o3,1 o3,2 o3,3

start
o1,1 x1,2 x1,3
x2,1 o2,2 x2,3
x3,1 x3,2 o3,3

1 3
o1,1 x1,2 o1,3
x2,1 o2,2 x2,3
o3,1 x3,2 o3,3

2 3
o1,1 x1,2 o1,3
x2,1 o2,2 o2,3
o3,1 o3,2 o3,3

わかった
d[a][b]は
a行とb行とa列とb列から構成されてるのでそれぞれ固定して全部チェックしたらドン
部分最適性があるしdp
d[i][j] := 命題i+1,j+1が???????

1,1 1,2 1,3 1,4 1,5
2,1 2,2 2,3 2,4 2,5
3,1 3,2 3,3 3,4 3,5
4,1 4,2 4,3 4,4 4,5
5,1 5,2 5,3 5,4 5,5

2,3に注目
2,3が塗られるかどうかは
行2:2,1     2,3 2,4 2,5
列2:1,2     3,2 4,2 5,2
行3:3,1 3,2     3,4 3,5
列3:1,3 2,3     4,3 5,3
をチェック

ほんまか？チェック
1,4(4,1)が○で今2,4(4,2)が塗られたら1,2と2,1も塗りたい
2を含む行列全部チェックすれば塗れるのでOK

塗り方
dp[i][j] = dp[i][k], dp[k][j], dp[k][i], dp[j][k]

実装がピンポイント過ぎてきつくなるのでdpの右辺の計算式を工夫してdp[i][k],dp[k][j]のみにしたい
すべての要素ですべての固定を試す（ピンポイントの緩和for:0-i-n,0-j-n,0-k-n）

ha-wakarann
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