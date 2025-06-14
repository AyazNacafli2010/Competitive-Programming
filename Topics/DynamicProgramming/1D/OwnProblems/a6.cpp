// C. Air Conditioner
#include <bits/stdc++.h>
#define int long long

struct seg {
	int time, low, high;
};
void solve() {
	int n, m; std::cin >> n >> m;
	std::vector<seg> a(n+1);
	a[0] = {0, m, m};
	for (int i = 1; i <= n; i++)
		std::cin >> a[i].time >> a[i].low >> a[i].high;
	std::vector<bool> dp(n+1,false);
	dp[0] = true;
	int min = m, max = m;
	for (int i = 1; i <= n; i++) {
		int d_t = a[i].time - a[i-1].time;
		if (dp[i-1] == false)
			break;
		min -= d_t;
		max += d_t;
		if (min > a[i].high || a[i].low > max) 
			break;
		dp[i] = true;
		min = std::max(min, a[i].low);
		max = std::min(max, a[i].high);
	}
	std::cout << (dp[n] == true ? "YES\n" : "NO\n");
}
main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tt; std::cin >> tt;
	while (tt --> 0) solve();
}