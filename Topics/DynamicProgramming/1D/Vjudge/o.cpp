#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define isz(x) (int)x.size()
#define long long long
using namespace std;
const int N = 2e5 + 5, INF = INT_MAX;
int a[N], dp[N];
void solve() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		dp[i] = INF;
	for (int i = 1; i <= n; i++) {
		set<int> st;
		for (int j = 1; j <= k && i - j >= 0; j++) {
			st.insert(a[i - j + 1]);
			dp[i] = min(dp[i], dp[i - j] + (int)st.size());
		}
	}
	cout << dp[n] << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}