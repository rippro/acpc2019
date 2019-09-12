#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define MAX 100005
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef pair<int,int> pii;

bool used[MAX];
int cnt[MAX],dist[MAX];
vector<vector<int> > G;
int n, t, s, g;

void last(int v){
    if(v == g)return;
    for(auto ne: G[v]){
        if(dist[ne] < dist[v]){
            cnt[ne]++;
            last(ne);
        }
    }
}

bool dfs(int now, int par){
    bool ret = true;
    if(now == g)ret = false;
    priority_queue<pii> q;
    for(auto ne: G[now])if(ne != par){
        if(used[ne] == 0)q.push(pii(dist[ne],ne));
    }
    while(q.size()/* && q.top().first > dist[now]*/){
        int v = q.top().second;
        q.pop();
        if(used[v])continue;
        cnt[v]++;
        if(dfs(v,now))cnt[now]++;
        else ret = false;
    }
    if(used[now] == 0){
        used[now]++;
    }
    return ret;
}

int main(){
    cin >> n >> t >> s >> g;
    s--,g--;
    G = vector<vector<int> > (n);
    vector<int> a(n),b(n),c(n);
    rep(i,n-1){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--,b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    rep(i,n)dist[i] = 1e9;
    dist[g] = 0;
    queue<int> q;
    q.push(g);
    while(q.size()){
        int v = q.front();
        q.pop();
        for(auto ne: G[v]){
            if(dist[ne] > dist[v]+1){
                dist[ne] = dist[v]+1;
                q.push(ne);
            }
        }
    }
    dfs(s,-1);
    rep(i,n-1){
        int sum = cnt[a[i]] + cnt[b[i]] - 1;
        if(c[i] <= sum*t){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
