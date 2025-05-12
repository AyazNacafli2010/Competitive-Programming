#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
int n, k;
vector<int> v;
bool check (int x) {
	int need = 0;
	for (int i = n / 2; i < n; i++) {
		if (x > v[i]) need += (x - v[i]);
		if (need > k) return false;
	}
	return need <= k;
}
main(){
	cin >> n >> k;
	v.resize(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	sort(all(v));
	int l = 0,r = (int)(1e18L),best = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		// cout << mid << ' ';
		if (check(mid)) {
			best = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << best << '\n';
}
