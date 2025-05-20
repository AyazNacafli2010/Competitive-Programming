#include <bits/stdc++.h>
#define int long long 

using namespace std;
void remax(int &a, int b) { 
	a = max(a,b); 
}
template <typename T>
using MnPq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
	int n, m, d; cin >> n >> m >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MnPq<int> pq;
	int answ = 0,sum = 0;
	auto add = [&](const int x) {
		if (x < 0)
			return;
		pq.push(x);
		sum += x;
		if (pq.size() == m) {
			sum -= pq.top();
			pq.pop();
		}
	};	
	for (int i = 0; i < n; i++) {
		int cur = sum + a[i] - d * (i+1);
		add(a[i]);
		// cout << cur << ' ';
		remax(answ,cur);
	}
	cout << answ << '\n';
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt; cin >> tt;
	while (tt --> 0) solve();
}
