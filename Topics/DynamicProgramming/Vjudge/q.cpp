#include <bits/stdc++.h>
#define long long long
using namespace std;
const long INF = (long)1e18L;
void solve() {
	int n; cin >> n;
	vector<long> a(n);
	vector<long> cnt(n+1);
	for (auto &it : a) {
		cin >> it;
		if (it < n)
			cnt[it]++;
	}
	long m = 0;
	while (cnt[m])
		m++;
	vector<long> dp(m+1,INF);
	dp[m] = 0;
	for (long i = m; i >= 1; i--)
		for (long j = 0; j < i; j++)
			dp[j] = min(dp[j], dp[i] + i * cnt[j]);
	cout << dp[0] - m << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while (t--) solve();
}