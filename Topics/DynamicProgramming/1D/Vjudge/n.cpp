#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define long long long
using namespace std;
const long N = 2e5 + 5;
int a[N],dp[N];
void solve() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= k && i - j >= 0; j++) {
			mx = max(mx, a[i - j + 1]);
			dp[i] = max(dp[i], mx * j + dp[i - j]);
		}
	}
	cout << dp[n] << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}