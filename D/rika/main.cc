#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

#define MAX 100005
#define rep(i,n) for(int i = 0; i < (n); i++)

typedef pair<int,int> pii;
map<pii,int> ma;

bool path[MAX];
vector<vector<int> > G;
int n, t, s, g;

int get(int a,int b){
    if(a == -1 || b == -1)return -1;
    if(a > b)swap(a,b);
    return ma[pii(a,b)];
}

void dec(int a, int b, int cnt){
    if(a == -1 || b == -1)return;
    if(a > b)swap(a,b);
    ma[pii(a,b)] -= cnt*t;
    return;
}

void dfs_path(int now, int par){
    if(now == g)path[now] = true;
    for(auto ne: G[now]){
        if(ne == par)continue;
        dfs_path(ne,now);
        if(path[ne]){
            path[now] = true;
            if(now != s)dec(now,ne,1);
        }
    }
}

int dfs(int now, int par){
    int ret = 0;
    priority_queue<pii> q;
    for(auto ne: G[now]){
        if(path[ne] || ne == par)continue;//s-gパス上にある頂点には行かない
        int tmp = dfs(ne,now);
        dec(now,ne,tmp);
        ret++;
        q.push(pii(get(now,ne),ne));
    }
    while(q.size()){
        int v = q.top().second;
        dec(now,v,q.size());
        q.pop();
    }
    return ret;
}

int main(){
    cin >> n >> t >> s >> g;
    s--,g--;
    G = vector<vector<int> > (n);
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
        if(a > b) swap(a,b);
        ma[pii(a,b)] = c;
    }
    dfs_path(s,-1);
    rep(i,n)if(path[i])dfs(i,-1);
    for(auto x: ma){
        //cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        if(x.second <= 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
