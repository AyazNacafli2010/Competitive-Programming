#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
#define isz(x) (int)x.size()

using namespace std;

constexpr int N = 2e5L + 5L, INF = (int)1e18L;
constexpr int MOD = 1e9L + 7L;
int pre[10] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};

void solve() {
	string t; cin >> t;
	int answ = 0;
	auto add = [&](int answ, int x) {
		int cur = (0 + answ) % 10;
		int delta = (x - cur + 10) % 10;
		return delta;
	};
	for (int i = isz(t) - 1; i >= 0; i--)
		answ += add(answ, t[i] - '0');
	cout << answ + isz(t);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	solve();
    return 0;
}