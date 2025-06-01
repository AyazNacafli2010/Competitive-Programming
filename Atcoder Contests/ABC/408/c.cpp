#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int INF = (int)1e18L;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n,0);
	while (m--) {
		int l, r; cin >> l >> r;
		l--, r--;
		a[l]++;
		if (r+1 < n)
			a[r+1]--;
	}
	vector<int> pre(n+1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + a[i-1];
	cout << *min_element(pre.begin()+1, pre.end()) << '\n';
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	solve();
    return 0;
}