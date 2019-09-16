#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef pair<int,int> pii;
#define INF 1e9
struct data{
    int r,a,w,t;
    bool operator<(const data &another) const
    {
        return r+t < another.r + another.t;
    };
};

int main(){
    int n;
    cin >> n;
    vector<data> v(n);
    rep(i,n){
        cin >> v[i].r >> v[i].a >> v[i].w >> v[i].t;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int dp[2][2005][2];
    rep(i,2)rep(j,2005)rep(k,2)dp[i][j][k] = -INF;
    rep(i,n){
        int now = i%2;
        int ne = 1 - now;
        dp[now][v[i].t][1] = max(dp[now][v[i].t][1], v[i].a);
        for(int j = 2000; j >= 0; j--)rep(k,2)if(dp[now][j][k] != -INF){
            int nxt = min(j-v[i].r, v[i].t);
            if(nxt > 0){
                if(k){
                    dp[now][nxt][1] = max(dp[now][nxt][1], dp[now][j][1] + v[i].w);
                }else{
                    dp[now][nxt][1] = max(dp[now][nxt][1], dp[now][j][0] + v[i].a);
                }
            }
            dp[ne][j][0] = max(dp[ne][j][0], dp[now][j][k]);
            dp[now][j][k] = -INF;
        }
    }
    int ans = 0;
    rep(i,2)rep(j,2005)rep(k,2)ans = max(ans, dp[i][j][k]);
    cout << ans << endl;
}
