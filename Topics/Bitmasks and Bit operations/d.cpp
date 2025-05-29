#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> b(n+1,0);
	for (int i = 1; i < n; i++)
		cin >> b[i];
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
		a[i] = (b[i] | b[i-1]);
	for (int i = 1; i < n; i++) {
		if ((a[i] & a[i+1]) != b[i]) {
			cout << "-1\n";
			return;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt; cin >> tt;
	while (tt --> 0) solve();
    return 0;
}