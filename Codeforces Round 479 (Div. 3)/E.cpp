#pragma GCC optimize("O3")
#include "bits/stdc++.h"

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//  Joe "Brown Bomber" Louis
//  G.O.A.T of Heavyweight

vvi g;
vi color;
bool ok = true;
void dfs(int u) { 
	color[u] = 1;
	if(g[u].size() != 2)
		ok = false;
	for(auto v : g[u]){
		if(!color[v]){
			dfs(v);
		}
	}
	color[u] = 2;
}
void solve(int cs){
    int n, m; 
	cin >> n >> m;
	g.resize(n+1);
	color.assign(n+1,0);
	for (int i = 1;i <= m;i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cycleComponents = 0;
	for(int i = 1;i <= n;i++){
		if(!color[i]){
			ok = true;
			dfs(i);
			if(ok)
				cycleComponents++;
		}
	}
	cout << cycleComponents << '\n';
	return;
}
signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cerr << "Case : " << cs << '\n';
        solve(cs);
    }
	return 0;
}
