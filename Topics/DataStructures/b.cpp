#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	vector<int>cnt(n,0);
	while (q --> 0) {
		int l, r; cin >> l >> r;
		l--,r--;
		cnt[l]++;
		if (r + 1 < n)
			cnt[r + 1]--;
	}
	int cur_sum = 0;
	for (int i = 0; i < n; i++) {
		cur_sum += cnt[i];
		cnt[i] = cur_sum;
	}
	sort(all(a));
	sort(all(cnt));
	int sum = 0;
	for (int i = 0;i < n;i++) sum += a[i] * cnt[i];
	cout << sum << '\n';
}
