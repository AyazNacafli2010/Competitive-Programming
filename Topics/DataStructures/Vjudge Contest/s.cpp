#include <bits/stdc++.h>
#define int long long
using namespace std;
using MxPq = priority_queue<int> ;
void solve() {
	MxPq pq;
	int n, k, answ = 0; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push(x);
		if ((n - i) % (k + 1) == 0) {
			answ += pq.top();
			pq.pop();
		}
	}
	cout << answ << '\n';
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) solve();
}