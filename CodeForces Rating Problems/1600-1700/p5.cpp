#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

void solve() {
	ll n, x; cin >> n >> x;
	vl a(n+1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vl pre(n+1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + a[i];
	vl dp(n+2,0);
	for (int i = n-1; i >= 0; i--) {
		int j = upper_bound(pre.begin(), pre.end(), pre[i] + x) - pre.begin();
		dp[i] = dp[j] + j - i - 1;
		// cout << i << ' ' << j << ' ' << dp[i] << ' ' << ' ' << a[i] << '\n';
	}
	ll sum = 0;
	for (int i = 0; i <= n; i++)
		sum += dp[i];
	cout << sum << '\n';
}
main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}
