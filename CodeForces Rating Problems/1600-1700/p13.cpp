#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N];
/**
	1. n - m * k < n / (m + 1)
	2. n - n / (m + 1) < m * k
	3. n * (m + 1) - n / (m + 1) < m * k
	4. n * m + n - n / (m + 1) < m * k
	5. n * m / (m + 1) < m * k
	6. n / (m + 1) < k
	7. n < k * (m + 1) ========> n - m * k < k 
	so a[i] = i mod k
	in other condition a[i] = i mod (n / (m + 1))
**/
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