#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
	vector<int> v(n);
	int mx = 0, mn = 1023;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx |= v[i];
		mn &= v[i];
	}
	cout << mx - mn << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int tt = 1; cin >> tt;
    while (tt --> 0) solve();
     
    return 0;
}