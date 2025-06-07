#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i <= n; i++)
		a[i] = 0;
	int num = max(k, n / (m+1));
	for (int i = 0; i < n; i++)
		a[i] = i % num;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}