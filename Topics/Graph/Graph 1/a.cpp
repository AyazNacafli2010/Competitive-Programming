#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define all(x) (x).begin(), (x).end()
#define isz(x) ((int)(x.size()))

using ll = long long;
using ld = long double;
using i128 = __int128_t;
using ull = unsigned long long;

template<typename X, typename Y> X& remin(X& x, const Y& y) { return x = x < y ? x : y; }

template<typename X, typename Y> X& remax(X& x, const Y& y) { return x = x > y ? x : y; }

const int N = 2e5 * 5;
bool cycle,  used[N];
vector<int> g[N];

void dfs(int u, int p) {
	used[u] = true;
	for (auto &v : g[u]) {
		if (used[v] == true && v != p) cycle = true;
		if (used[v] == false) dfs(v, u);
	}
}
void run_case(){
	int n, m; cin >> n >> m;
	fill(used, used + n + 1, false);
	for (int i = 1; i <= n; i++) {
		g[i * 2].push_back(i * 2 - 1);
		g[i * 2 - 1].push_back(i * 2);
	}
	for (int i = 1; i <= m; i++) {
		int a, b; char x, y;
		cin >> a >> x >> b >> y;
		int u = a * 2 - (x == 'B');
		int v = b * 2 - (y == 'B');
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int components = 0, cycles = 0;
	for (int i = 1; i <= n * 2; i++) {
		if (used[i] == false) {
			cycle = false;
			dfs(i, -1);
			components++;
			if (cycle) cycles++;
		}
	}
	cout << cycles << ' ' << components - cycles << '\n';
	return;
}
signed main() {
   ios::sync_with_stdio(false); 
	cin.tie(nullptr);

	int tests = 1;
	// cin >> tests;
	while (tests --> 0)
		run_case();
   return 0;
}