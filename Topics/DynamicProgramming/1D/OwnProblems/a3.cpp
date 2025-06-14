// C. Woodcutters
#include <bits/stdc++.h>
#define int long long

struct seg {
	int left, zero, right;
};
main(){
	int n; std::cin >> n;
	std::vector<int> x(n), h(n);
	for (int i = 0; i < n; i++) 
		std::cin >> x[i] >> h[i];
	std::vector<seg> pos(n);
	for (int i = 0; i < n; i++) {
		pos[i].left = x[i] - h[i];
		pos[i].zero = x[i];
		pos[i].right = x[i] + h[i];
	}
	int answ = 0;
	std::vector<std::vector<int>> dp(n,std::vector<int>(3,0)); // left 0 right
	dp[0][0] = 1;
	dp[0][1] = 0;
	if (pos[0].right < pos[1].zero) 
		dp[0][2] = 1;
	for (int i = 1; i < n; i++) {
		// to left 
		if (pos[i].left > pos[i-1].zero) 
			dp[i][0] = std::max(dp[i-1][0],dp[i-1][1])+1;
		if (pos[i].left > pos[i-1].right) 
			dp[i][0] = std::max(dp[i][0],dp[i-1][2]+1);
		
		// do not move
		dp[i][1] = std::max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
		
		// to right 
		int temp = std::max({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+1;
		if (i == n - 1 || pos[i].right < pos[i+1].zero)
			dp[i][2] = temp;
	}
	for (int i = 0; i < n; i++) {
		answ = std::max({answ, dp[i][0], dp[i][1], dp[i][2]});
		// std::cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
	}
	std::cout << answ;
}