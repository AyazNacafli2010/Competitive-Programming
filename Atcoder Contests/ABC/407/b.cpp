#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5L + 5L, INF = (int)1e18L;
constexpr int MOD = 1e9L + 7L;

void solve() {
	int X, Y; cin >> X >> Y;
	int answ = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i + j >= X || abs(i - j) >= Y) {
				answ++;
			}				
		}
	}
	cout << fixed << setprecision(30) << (answ / 36.0) << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int t = 1; // cin >> t;
	while (t--) solve();
    return 0;
}