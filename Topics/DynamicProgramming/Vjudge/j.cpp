#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define isz(x) (int)x.size()
#define long long long
using namespace std;
const int N = 2e5 + 5, INF = INT_MAX;
long a[N], dp[N];
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		dp[i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i - 1; j >= 0; j--)
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
	cout << *max_element(dp + 1, dp + 1 + n) << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}