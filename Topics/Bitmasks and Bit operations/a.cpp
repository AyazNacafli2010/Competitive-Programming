#include <bits/stdc++.h>
void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    int min_sum = 0;
    for (int i = 0; i < n; i++)
        min_sum |= a[i];
	std::cout << min_sum << '\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int tt = 1; std::cin >> tt;
	while (tt --> 0) solve();
	return 0;
}
