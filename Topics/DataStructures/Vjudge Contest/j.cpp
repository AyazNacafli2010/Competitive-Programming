#include <bits/stdc++.h>
#define int long long
using namespace std;
using MxPq = priority_queue<int>;
using MnPq = priority_queue<int, vector<int>, greater<int>>;
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> pre(n+1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++) 
		pre[i] = pre[i-1] + a[i];
	MxPq pq;
	int x = pre[m];
	int answ{};
	for (int i = m; i >= 1; i--) {
		if (pre[i] < x) {
			int diff = x - pre[i];
			while (diff > 0) {
				int Top = pq.top();
				pq.pop();
				x -= Top * 2;
				diff -= Top * 2;
				answ++;
			}
		}
		pq.push(a[i]);
	}
	x = pre[m];
	MnPq pq2;
	for (int i = m + 1; i <= n; i++ ) {
		pq2.push(a[i]);
		if (pre[i] < x) {
			int diff = x - pre[i];
			while (diff > 0) {
				int Top = pq2.top();
				pq2.pop();
				x += Top * 2;
				diff += Top * 2;
				answ++;
			}
		}
	}
	cout << answ << '\n';
}
signed main(){
	int tt = 1; cin >> tt;
	while (tt --> 0) solve();
}