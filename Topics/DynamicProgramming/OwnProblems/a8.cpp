#include <bits/stdc++.h>
void remax(int &a, int b) {
	a = std::max(a,b);
}
void remin(int &a, int b) {
	a = std::min(a,b);
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int tt; std::cin >> tt;
	while (tt --> 0) {
		int n; std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++)
			std::cin >> a[i];
		std::vector<int> dp(n, n); // count of i to n  
		dp[n-1] = 1;
		for (int i = n-2; i >= 0; i--) {
			dp[i] = std::min(dp[i+1] + 1, [&](){
					if (a[i] + i + 1 > n)
						return (int)1e18L;
					else if (a[i] + i + 1 == n)
						return 0;
					return dp[a[i] + i + 1];
				}());
		}
		int answ = dp[0];
		std::cout << answ << '\n';
	}
	return 0;
}