#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define int long long
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

class StronglyConnectedComponents{
	private:
		vector<bool> used;
		vector<int> vs; //帰りがけ順の並び
		void dfs(int v){
			used[v] = true;
			rep(i,g[v].size()){
				if(not used[g[v][i]]) dfs(g[v][i]);
			}
			vs.emplace_back(v);
		}
		void rdfs(int v, int k){
			used[v] = true;
			cmp[v] = k;
			rep(i,rg[v].size()){
				if(not used[rg[v][i]]) rdfs(rg[v][i], k);
			}
		}
	public:
		typedef vector<vector<int>> graph;
		const int v; // 頂点数
		int nv; // SCCした後の頂点数
		graph g, rg; // グラフ、辺が逆になったグラフ
		vector<int> cmp; //属する強連結成分のトポロジカル順序

		StronglyConnectedComponents(int v) : used(v), v(v), g(v), rg(v), cmp(v) { }

		void addEdge(int from, int to){
			g[from].emplace_back(to);
			rg[to].emplace_back(from);
		}
		int solve(){ // 強連結成分分解をしたあとのグラフの頂点数を返す
			fill(all(used),0);
			vs.clear();
			rep(i,v){
				if(not used[i]) dfs(i);
			}
			fill(all(used),0);
			int k = 0;
			for(int i = vs.size() - 1; i >= 0; i--){
				if(not used[vs[i]]) rdfs(vs[i], k++);
			}
			return nv = k;
		}
		graph getCssGraph(vector<vector<int>>& node){
			node = vector<vector<int>>(nv); // node[i]:=SCCによって頂点iに同一視された頂点
			graph res(nv); // CSSしたあとのグラフ
			rep(i,v){
				node[cmp[i]].emplace_back(i);
				for(auto to : g[i]){
					if(cmp[i] == cmp[to]) continue;
					res[cmp[i]].emplace_back(cmp[to]);
				}
			}
			return res;
		}
		void out(){
			rep(i,v){ cout << cmp[i] << ' '; } cout << endl;
		}
};

signed main(){
	int n, m;
	cin >> n >> m;

	StronglyConnectedComponents scc(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		scc.addEdge(a,b);
	}
	scc.solve();

	vector<vector<int>> node;
	auto g = scc.getCssGraph(node);

	vector<vector<int>> ans(n);
	rep(i,node.size()){
		rep(j,node[i].size()){
			rep(k,node[i].size()){
				ans[node[i][j]].emplace_back(node[i][k]);
			}
		}
	}

	rep(i,n){
		sort(all(ans[i]));
		rep(j,ans[i].size()){
			if(j) cout << ' ';
			cout << ans[i][j] + 1;
		}
		cout << endl;
	}
}
