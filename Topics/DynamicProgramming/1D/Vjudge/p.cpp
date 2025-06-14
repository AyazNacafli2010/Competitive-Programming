#include <bits/stdc++.h>
#define long long long
using namespace std;
const long N = 2e5 + 5;
long a[N], pos[N], dp[N][2], t;
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		pos[i] = -1, dp[i][1] = dp[i][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
		if (pos[a[i]] != -1) {
			int last = pos[a[i]];

			int a = i - last + 1 + dp[last][0];
			int b = i - last + dp[last][1];
			
			dp[i][1] = max(a,b);
		}
		pos[a[i]] = i;
	}
	cout << max(dp[n][1], dp[n][0]) << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while (t--) 
		solve();
}