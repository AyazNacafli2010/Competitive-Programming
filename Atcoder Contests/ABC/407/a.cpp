#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5L + 5L, INF = (int)1e18L;
constexpr int MOD = 1e9L + 7L;

void solve() {
	double A, B; cin >> A >> B;
	double x = A / B;
	if (ceil(x) - x <= abs(x - floor(x)))
		cout << ceil(x) << '\n';
	else
		cout << floor(x) << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int t = 1; // cin >> t;
	while (t--) solve();
    return 0;
}