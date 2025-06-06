#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 4e5 + 5;
vector<int> g[N], cost[N];
int w[N], tin[N], tout[N];
int cnt, t, st[N * 4];

void dfs(int u, int p) {
	tin[u] = ++t;
	for (auto &v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	tout[u] = ++t;
}
void build(int l, int r, int v) {
	if (l == r) {
		st[v] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,v<<1);
	build(mid+1,r,v<<1|1);
	st[v] = st[v<<1] + st[v<<1|1];
}
void update(int x,int l, int r, int val, int v) {
	if (x < l || x > r)
		return;
	if (l == r) {
		st[v] += val;
		return;
	}	
	int mid = (l + r) / 2;
	update(x, l, mid, 1, v<<1);
	update(x, mid+1, r, 1, v<<1|1);
	st[v] = st[v<<1] + st[v<<1|1];
}	
int get(int l,int r,int a, int b, int v) {
	if (l > b || a > r) return 0;
	if (a <= l && r <= b) return st[v];
	int mid = (l + r) / 2;
	return get(l, mid, a, b, v<<1) + get(mid+1, r, a, b, v<<1|1);
}

void solve() {
	int n; cin >> n;
	build(1, 2 * n, 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		cost[i].clear();
		g[i].clear();
		tin[i] = tout[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		cost[w[i]].push_back(i);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	t = 0; cnt = 0;
	dfs(1, -1);
	for (int node = n; node >= 1; node--) {
		for (auto &it : cost[node]) {
			int a = get(1, 2 * n, tin[it], tout[it], 1);
			if (a != cnt) {
				cout << it << endl;
				return;
			}
		}
		for (auto &it : cost[node]) {
			update(tin[it], 1, 2*n, 1, 1);
			cnt++;
		}
	}
	cout << 0 << endl;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt; cin >> tt;
	while (tt--)
		solve();
	
	return 0;
}