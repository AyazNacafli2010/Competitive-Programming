#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int INF = (int)1e18L;

void solve() {
	int n; cin >> n;
	set<int>s;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	cout << s.size() << '\n';
	for (auto &it : s)
		cout << it << ' ';
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	solve();
    return 0;
}