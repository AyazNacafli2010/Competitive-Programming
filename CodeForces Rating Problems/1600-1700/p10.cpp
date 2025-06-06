#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int deg[N], sub[N];

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		g[i].clear(), deg[i] = 0;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		deg[i] = g[i].size();
	set<pair<int,int>> st;
	for (int i = 1; i <= n; i++)
		st.insert({deg[i], i});
	int answ = 0;
	for (int i = 1; i <= n; i++) {
		int cur, deg_i = deg[i];
		cur = deg_i;
		for (auto &it : g[i]) {
			st.erase({deg[it], it});
			st.insert({deg[it]-1, it});
		}
		st.erase({deg_i, i});
		cur += st.rbegin()->first - 1;
		st.insert({deg_i, i});
		for (auto &it : g[i]) {
			st.insert({deg[it], it});
			st.erase({deg[it]-1, it});
		}
		answ = max(answ, cur);
	}
	cout << answ << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}