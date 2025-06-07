#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
vector<int> g[N];
int a[N], ans[N];

/// Majority is just i not started at i and has majority i!
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		ans[i] = 0, g[i].clear();
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		map<int,int> chk;
		for (auto &it : g[i])
			chk[a[it]]++;
		chk[a[i]]++;
		for (auto [x,y] : chk)
			if (y >= 2)
				ans[x] = 1;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i];
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}