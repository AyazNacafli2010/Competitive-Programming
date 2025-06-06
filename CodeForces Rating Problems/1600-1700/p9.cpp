#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int deg[N];

void solve() {
	int n; cin >> n;
	fill(deg, deg + n + 1, 0);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		deg[u]++;
		deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 2) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}