// C. Sweets Eating
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define int long long
main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m; std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(all(a));
	std::vector<int> ans(n);
	int sum{};
	for (int i = 0; i < n; i++) {
		sum += a[i];
		ans[i] = sum;
		if (i >= m)
			ans[i] += ans[i-m];
	}
	for (auto &it : ans)
		std::cout << it << ' ';
	return 0;
}