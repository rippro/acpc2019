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

signed main(){
	int n;
	string s;
	cin >> n >> s;

	int y = 0, x = 0;
	for(auto c : s){
		if(c >= 'A' and c <= 'M') y--;
		if(c >= 'N' and c <= 'Z') y++;
		if(c >= 'a' and c <= 'm') x++;
		if(c >= 'n' and c <= 'z') x--;
	}

	string ans;
	rep(i,abs(y)){
		if(y < 0) ans+='A';
		else ans+='N';
	}
	rep(i,abs(x)){
		if(x < 0) ans+='n';
		else ans+='a';
	}

	cout << ans.size() << endl << ans << endl;
}
