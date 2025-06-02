#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(m);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < m; i++) 
		cin >> b[i];
    
	sort(a.begin(), a.end());
	if (n != 1) {
		ll GCD = a[1] - a[0];
		for (int i = 2; i < n; i++) 
			GCD = gcd(GCD, a[i] - a[0]);
		for (int i = 0; i < m; i++)
			cout << gcd(GCD, b[i] + a[0]) << ' ';
		return 0;
	}
	for (int i = 0; i < m; i++)
		cout << b[i] + a[0] << ' ';
	return 0;
}
