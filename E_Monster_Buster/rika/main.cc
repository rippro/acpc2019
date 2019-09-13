#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef pair<int,int> pii;
int main(){
    int n;
    cin >> n;
    vector<int> r(n),a(n),w(n),t(n);
    priority_queue<pii> q;
    rep(i,n){
        cin >> r[i] >> a[i] >> w[i] >> t[i];
        //q.push(pii(r[i]+t[i],i));
    }
    rep(x,n){
        int ma = t[x];
        vector<vector<int> > dp(n,vector<int>(ma+1,-INF));
        dp[0][0] = a[x];
        rep(i,ma)if(dp[0][i] >= 0 && i+r[x] <= ma){
            dp[0][i+r[x]] = max(dp[0][i+r[x]], dp[0][i] + w[x]);
        }
        rep(i,n)rep(j,ma+1){

        }
    }
    vector<vector<int> > dp(2005,vector<int>(2005,-INF));
    dp[0][0] = 0;
    //dp[i][j] := i曲目まで見てj秒つかったときの攻撃力の最大値
    while(q.size()){
        int ind = q.top().second;
        q.pop();
        int i = n - q.size();

    }
}
