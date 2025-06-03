#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

const int INF = (int)1e18L*4L;
int diff(int a,int b,int c) {
	return (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);
}
void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n), b(m), c(k);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	for (auto &it : c) cin >> it;
	sort(all(a)); sort(all(b)); sort(all(c));
	int sum1 = INF, sum2 = INF, sum3 = INF;
	for (int i = 0; i < n; i++) {
		auto it1 = lower_bound(b.begin(), b.end(), a[i]);
		vector<int> can1;
		if (it1 != b.end()) can1.push_back(*it1);
		if (it1 != b.begin()) can1.push_back(*prev(it1));
		auto it2 = lower_bound(c.begin(), c.end(), a[i]);
		vector<int> can2;
		if (it2 != c.end()) can2.push_back(*it2);
		if (it2 != c.begin()) can2.push_back(*prev(it2));
		
		for (auto &x : can1) 
			for (auto &y : can2)
				sum1 = min(sum1, diff(a[i], x, y));
	}
	for (int i = 0; i < m; i++) {
		auto it1 = lower_bound(a.begin(), a.end(), b[i]);
		vector<int> can1;
		if (it1 != a.end()) can1.push_back(*it1);
		if (it1 != a.begin()) can1.push_back(*prev(it1));
		auto it2 = lower_bound(c.begin(), c.end(), b[i]);
		vector<int> can2;
		if (it2 != c.end()) can2.push_back(*it2);
		if (it2 != c.begin()) can2.push_back(*prev(it2));
		
		for (auto &x : can1) 
			for (auto &y : can2)
				sum2 = min(sum2, diff(b[i], x, y));
	}
	for (int i = 0; i < k; i++) {
		auto it1 = lower_bound(b.begin(), b.end(), c[i]);
		vector<int> can1;
		if (it1 != b.end()) can1.push_back(*it1);
		if (it1 != b.begin()) can1.push_back(*prev(it1));
		auto it2 = lower_bound(a.begin(), a.end(), c[i]);
		vector<int> can2;
		if (it2 != a.end()) can2.push_back(*it2);
		if (it2 != a.begin()) can2.push_back(*prev(it2));
		
		for (auto &x : can1) 
			for (auto &y : can2)
				sum3 = min(sum3, diff(c[i], x, y));
	}
	// cout << sum1 << ' ' << sum2 << ' ' << sum3 << '\n';
	cout << min({sum1, sum2, sum3}) << '\n';
}
main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
