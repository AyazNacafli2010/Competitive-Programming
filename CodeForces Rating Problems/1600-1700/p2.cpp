#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

const int N = 2e5 + 5;
vi adj[N];
int color[N];
vi bfs() {
	memset(color, 0, sizeof(color));
	vi A;
	queue<int> q;
	q.push(1);
	color[1] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		A.push_back(v);
		for (auto &u : adj[v]) {
			if (color[u] == 0) {
				q.push(u);
				color[u] = 1;
			}
		}
	}
	return A;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vi a(n), pos(n+1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		pos[a[i]] = i;
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end(), [&](int p1, int p2) {
			return pos[p1] < pos[p2];
		});
	if (bfs() == a) cout << "Yes";
	else cout << "No";
	return 0;
}
