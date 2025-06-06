#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<int> g[N];
int color[N];

void dfs(int u) {
	color[u] = 1;
	for (auto &v : g[u])
		if (color[v] == 0)
			dfs(v);
	color[u] = 2;
}

void solve() {
	int n; cin >> n;
	for (int i = 0; i < N; i++) {
		g[i].clear();
		color[i] = 0;
	}
	string a, b; 
	cin >> a >> b;
	a = "&" + a; b = "&" + b;
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[i]) {
			cout << "-1\n";
			return;
		}
		if (a[i] < b[i]) {
			g[b[i] - 'a'].push_back(a[i] - 'a');
			g[a[i] - 'a'].push_back(b[i] - 'a');
		}
	}
	int answ = N;
	for (int i = 0; i < N; i++)
		if (color[i] == 0)
			dfs(i), answ--;
	cout << answ << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--)
		solve();
	return 0;
}