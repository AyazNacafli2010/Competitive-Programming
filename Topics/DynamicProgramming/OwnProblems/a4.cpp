// C. Mortal Kombat Tower
#include <bits/stdc++.h>
#define int long long

void solve() {
	int n; std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	a.push_back(0);
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(2,(int)1e18));
	dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int turn = 0; turn <= 1; turn++) {
			dp[i+1][1] = std::min(dp[i+1][1], dp[i][0]);
			dp[i+1][0] = std::min(dp[i+1][0], dp[i][1] + a[i]);
			
			if (i + 2 <= n) {
				dp[i+2][1] = std::min(dp[i+2][1], dp[i][0]);
				dp[i+2][0] = std::min(dp[i+2][0], dp[i][1] + a[i] + a[i+1]);				
			}
		}
	}
	std::cout << std::min(dp[n][0],dp[n][1]) << '\n';
}
main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tt; std::cin >> tt;
	while (tt --> 0) solve();
}