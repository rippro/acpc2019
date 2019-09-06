//SCC
#include<iostream>
#include<vector>
using namespace std;
#define MAX 305
int n;
vector<int> g[MAX],rg[MAX],vs;
int used[MAX],cmp[MAX];

void dfs(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if(!used[g[v][i]])dfs(g[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = 1;
    cmp[v] = k;
    for(int i = 0; i < rg[v].size(); i++){
        if(!used[rg[v][i]])rdfs(rg[v][i],k);
    }
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for(int v = 0; v < n; v++){
        if(!used[v])dfs(v);
    }
    memset(used,0,sizeof(used));
    int k = 0;
    for(int i = vs.size()-1; i >= 0; i--){
        if(!used[vs[i]])rdfs(vs[i],k++);
    }
    for(int i = 0; i < n; i++){
        int num = cmp[i];
        vector<int> ans;
        for(int j = 0; j < n; j++){
            if(cmp[j] == num)ans.push_back(j);
        }
        for(int j = 0; j < ans.size(); j++){
            if(j)cout << " ";
            cout << ans[j]+1;
        }
        cout << endl;
    }
}
