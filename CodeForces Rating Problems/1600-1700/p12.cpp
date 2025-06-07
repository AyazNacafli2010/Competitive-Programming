#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
/// operation 1 => floor (n)
/// operation 2 => ceil  (m)
/// obs :: 1.floor next 2.ceil - maximum other minimum

int MIN(int x, int n, int m) {
	while (m --> 0 && x > 1)
		x = (x + 1) / 2;
	while (n --> 0 && x > 0)
		x /= 2;
	return x;
}
int MAX(int x, int n, int m) {
	while (n --> 0 && x > 0)
		x /= 2;
	while (m --> 0 && x > 1)
		x = (x + 1) / 2;
	return x;
}
void solve() {
	int x, n, m;
	cin >> x >> n >> m;
	cout << MIN(x,n,m) << " " << MAX(x,n,m) << endl;
	return;
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}