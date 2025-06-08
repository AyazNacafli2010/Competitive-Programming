#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int a[N], d[N];

void solve() {
	int n, k; 
	cin >> n >> k;
	string s; 
	cin >> s;
	d[n-1] = (s[n-1] == '1' ? 1 : -1);
	priority_queue<int> pq;
	for (int i = n - 2; i >= 0; i--) {
		d[i] = d[i+1] + (s[i] == '1' ? 1 : -1);
		pq.push(d[i+1]);
	}
	int answ = 1;
	while (k > 0 && size(pq)) {
		k -= pq.top();
		pq.pop();
		answ++;
	}
	cout << (k > 0 ? -1 : answ) << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}