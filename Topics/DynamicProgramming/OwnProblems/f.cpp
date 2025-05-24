#include <bits/stdc++.h>
#define int long long

void solve() {
	int l, r; std::cin >> l >> r;
	int answ = 0;
	for (int i = 0; i <= 9; ++i)
		answ += r / (int)pow(10,i) - l / (int)pow(10,i);
	std::cout << answ << '\n';
}
main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int tt; std::cin >> tt;
	while (tt --> 0) solve();
}