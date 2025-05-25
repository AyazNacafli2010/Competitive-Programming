// B. Bargaining Table
#include <bits/stdc++.h>
#define int long long
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
void remax(int &a,const int b) { a = std::max(a,b); }
main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m; std::cin >> n >> m;
	vvi a(n,vi(m));
	for (int i = 0; i < n; i++) {
		std::string s; std::cin >> s;
		for (int j = 0; j < m; j++)
			a[i][j] = s[j] - '0';
	}
	vvi pre(n+1,vi(m+1, 0));
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i-1][j-1];
	auto sum = [&](int i,int j,int k,int p) {
		return pre[k][p] - pre[i-1][p] - pre[k][j-1] + pre[i-1][j-1];
	};
	int answ{};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = i; k <= n; k++)
				for (int p = j; p <= m; p++)
					if (sum(i,j,k,p) == 0)
						remax(answ, 2 * (k - i + 1 + p - j + 1));
	std::cout << answ << std::endl;
	return 0;
}