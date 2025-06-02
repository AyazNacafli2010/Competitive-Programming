#include <bits/stdc++.h>
#define int long long
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int INF = (int)1e18L;

main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	vi c(n+1);
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	vector<string> s(n+1);
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	vector<vector<int>> dp(n+1, vector<int>(2,INF));
	dp[1][0] = 0;
	dp[1][1] = c[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i-1][1] == INF && dp[i-1][0] == INF) 
			continue;
		string temp = s[i-1], temp2 = s[i];
		reverse(temp.begin(), temp.end());
		reverse(temp2.begin(), temp2.end());
		if ( s[i] >= s[i-1] ) dp[i][0] = dp[i-1][0];
		if ( s[i] >= temp ) dp[i][0] = min(dp[i-1][1], dp[i][0]);
		if ( temp2 >= s[i-1] ) dp[i][1] = dp[i-1][0] + c[i];
		if ( temp2 >= temp ) dp[i][1] = min(dp[i-1][1] + c[i], dp[i][1]); 
		
		// cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
	if (dp[n][1] == INF && dp[n][0] != INF)
		cout << dp[n][0];
	if (dp[n][1] != INF && dp[n][0] == INF)
		cout << dp[n][1];
	if (dp[n][1] == INF && dp[n][0] == INF)
		cout << -1;
	if (dp[n][1] != INF && dp[n][0] != INF)
		cout << min(dp[n][1], dp[n][0]) << '\n';
	return 0;
}
