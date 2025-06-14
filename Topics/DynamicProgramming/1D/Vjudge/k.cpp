#include <bits/stdc++.h>
#define long long long
using namespace std;
const long N = 2e5 + 5;
int a[N], dp[N];
void solve() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		dp[i] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (abs(a[i] - a[j]) <= k)
				dp[i] = max(dp[i] ,dp[j] + 1);
	cout << *max_element(dp, dp + n) << endl;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}