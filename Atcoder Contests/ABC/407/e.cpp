#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int INF = (int)1e18L;
void solve() {
	int n; cin >> n;
	vector<int> a(n*2+1);
	for (int i = 1; i <= 2*n; i++)
		cin >> a[i];
	int answ = 0;
	a[0] = -INF;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		pq.push(a[i*2-2]);
		pq.push(a[i*2-1]);
		int cur = pq.top(); pq.pop();
		answ += cur;
	}
	cout << answ << '\n';
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt = 1; cin >> tt;
	while (tt --> 0) solve();
    return 0;
}