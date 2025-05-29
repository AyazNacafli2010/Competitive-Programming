#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n, m; cin >> n >> m;
	cout << n * m << '\n';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << (i << 8) + j << (j == m - 1 ? '\n' : ' ');
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1; cin >> tt;
	while (tt --> 0) solve();
}