#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int N = 2e5 + 5;
vector<int> g[N];
int dis[N], sub[N], income[N], color[N], color2[N];

void bfs() {
	queue<int> q;
	q.push(1);
	color[1] = 1;
	dis[1] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto u : g[v]) {
			if (color[u] == 0) {
				color[u] = 1;
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
	}
}
void dfs(int u) {
	color2[u] = 1;
	sub[u] = 1;
	for (auto &v : g[u]) {
		if (color2[v] == 0) {
			dfs(v);
			sub[u] += sub[v];
		}
	}
	color2[u] = 2;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k; cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	dfs(1);
	for (int i = 1; i <= n; i++) {
		income[i] = dis[i] - sub[i] + 1;
		// cout << dis[i] << ' ' << sub[i] << '\n';
	}
	sort(income + 1, income + n + 1, greater<int>());
	cout << accumulate(income + 1, income + k + 1, 0LL) << '\n';
	return 0;
}
