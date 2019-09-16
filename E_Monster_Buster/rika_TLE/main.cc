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
    void print(){
        cout << r << " " << a << " " << w << " " << t << endl;
    }
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
    //cout << endl;
    //rep(i,n)v[i].print();
    int ans = 0;
    rep(x,n){
        int ma = v[x].t;
        //cout << endl;
        //cout << "x= " << x << " " << ma << " " << v[x].a << endl;
        vector<vector<vector<int> > > dp(2,vector<vector<int> >(ma,vector<int>(2,0)));
        dp[0][0][0] = v[x].a;
        rep(i,ma)if(dp[0][i][0] && i+v[x].r < ma){
            dp[0][i+v[x].r][0] = max(dp[0][i+v[x].r][0], dp[0][i][0] + v[x].w);
        }
        rep(i,n)if(i != x){
            int ind = i - (i > x);
            int now = ind%2;
            int ne = 1 - now;
            //cout << "!" << v[i].a << " " << v[i].w << endl;
            rep(j,ma)rep(k,2)if(dp[now][j][k]){
                //cout << ind << " " << j << " " << k << " " << dp[now][j][k] << endl;
                int nxt = max(j+v[i].r, ma-v[i].t);
                if(nxt < ma){
                    if(k){
                        dp[now][nxt][1] = max(dp[now][nxt][1], dp[now][j][1] + v[i].w);
                    }else{
                        dp[now][nxt][1] = max(dp[now][nxt][1], dp[now][j][0] + v[i].a);
                    }
                }
                dp[ne][j][0] = max(dp[ne][j][0], dp[now][j][k]);
                dp[now][j][k] = 0;
            }
        }
        rep(i,2)rep(j,ma)rep(k,2)ans = max(ans, dp[i][j][k]);
        //cout << "!" << x << " " << ans <<endl;
    }

    cout << ans << endl;
}
