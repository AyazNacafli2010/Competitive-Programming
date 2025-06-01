#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int INF = (int)1e18L;

void solve() {
	int n, s; cin >> n >> s;
	vector<int> a(n+1);
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int mx = -1;
	for (int i = 1; i <= n; i++)
		mx = max(mx, a[i] - a[i-1]);
	if (mx > s) 
		cout << "No";
	else
		cout << "Yes";
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	solve();
    return 0;
}