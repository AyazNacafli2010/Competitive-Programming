#include <bits/stdc++.h>
#define int long long
#define isz(x) (int)x.size()
using namespace std;

constexpr int mod = 998244353;

void solve() {
	int n; cin >> n;
	vector<int> a(n+1), pre(n+1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i-1] ^ a[i];
	}
	int x0 = 0, x1 = 0;
	string s; cin >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') x1^=a[i];
		else x0 ^= a[i];
	}
	int q; cin >> q;
	while (q --> 0) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r; cin >> l >> r;
			x0 = (x0 ^ pre[r] ^ pre[l-1]);
			x1 = (x1 ^ pre[r] ^ pre[l-1]);
		} 
		else {
			int g; cin >> g;
			if (g == 0) cout << x0 << '\n';
			else cout << x1 << '\n';
		} 
	}
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int tt ; cin >> tt;
	while (tt --> 0) solve();
    return 0;
}
