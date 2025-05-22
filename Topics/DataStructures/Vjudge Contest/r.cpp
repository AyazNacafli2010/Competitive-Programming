#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
using MnPq = priority_queue<T, vector<T>, greater<T>>;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	MnPq<int> pq;
	int answ = 0;
	pq.push(a[0]);
	for (int i = 1; i < n; i++) {
		int Top = pq.top();
		if (Top < a[i]) {
			answ += a[i] - Top;
			pq.pop();
			pq.push(a[i]);
		}
		pq.push(a[i]);
	}
	cout << answ;
}