#include <bits/stdc++.h>
#define int long long
using namespace std;

int ask(int x) {
	cout << "- " << x << endl;
	cin >> x;
	return x;
}
void solve() {
	int n; cin >> n;
	int cur = 0, d = 0;
	for (int i = 0; i < 30 && __builtin_popcount(cur) != n; i++) {
		int newN = ask(1 << i);
		d += (1 << i);
		for (int j = i; j <= i + newN - n; j++) 
			cur |= (1<<j);
		if (newN >= n) 
			i += newN - n;
		n = newN;
	}
	cout << "! " << cur + d << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int tt = 1; cin >> tt;
	while (tt --> 0) solve();
    return 0;
}