#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 5, INF = 4*(int)1e18L;
int a[N], b[N], g[N][N];
int cost = 0, n;

void part1() {
	vector<vector<int>> dp(n+1, vector<int>(2,INF));
	dp[0][0] = 0;
	dp[0][1] = a[1];
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				bool chk = true;
				for (int j = 1; j <= n; j++) {
					chk &= (g[i][j] + x != g[i-1][j] + y);
				}
				if (chk) {
					if (x == 0) {
						dp[i][x] = min(dp[i][x], dp[i-1][y]);
					} else {
						dp[i][x] = min(dp[i][x], dp[i-1][y] + a[i]);
					}
				}
			}
		}
	}
	// cout << cost << ' ';
	cost += min(dp[n][1], dp[n][0]);
}
void reverse_matrix() {
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++)
			swap(g[i][j], g[j][i]);
}
void part2() {
	vector<vector<int>> dp(n+1, vector<int>(2,INF));
	dp[0][0] = 0;
	dp[0][1] = b[1];
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				bool chk = true;
				for (int j = 1; j <= n; j++) {
					chk &= (g[i][j] + x != g[i-1][j] + y);
				}
				if (chk) {
					if (x == 0) {
						dp[i][x] = min(dp[i][x], dp[i-1][y]);
					} else {
						dp[i][x] = min(dp[i][x], dp[i-1][y] + b[i]);
					}
				}
			}
		}
	}
	// cout << cost << endl;
	cost += min(dp[n][1], dp[n][0]);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	cost = 0;
	part1(); /// Code get so big and i decide devide it in 2 parts :)
	reverse_matrix();
	part2();
	if (cost >= INF)  cout << "-1\n";
	else cout << cost << "\n";
	return;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}