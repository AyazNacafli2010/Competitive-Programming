// A. Next Test //
#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++) {
		if (i + 1 != a[i]) {
			cout << i + 1 << ' ';
			return;
		}
	}
	cout << n + 1 << ' ';
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}