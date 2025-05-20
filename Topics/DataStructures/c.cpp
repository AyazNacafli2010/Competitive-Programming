#include <bits/stdc++.h>
#define isz(x) (int)x.size()
#define int long long
using namespace std;

using vi = vector<int>;
void solve() {
	int n; cin >> n;
	vi a(n);
	map<int,int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<int> cnt;
	for (auto [x,y] : mp)
		cnt.push_back(y);
	sort(cnt.begin(),cnt.end());
	int res = (int)1e18L;
	vi pre(isz(cnt)+1,0),suf(isz(cnt)+2,0);
	for (int i = 1; i <= isz(cnt); i++)
		pre[i] = pre[i-1] + cnt[i-1];
	for (int i = isz(cnt) - 1; i >= 0; i--)
		suf[i] = suf[i+1] + cnt[i];
	for (int i = 1; i <= isz(cnt); i++)
		res = min(res, pre[i-1] + suf[i] - (isz(cnt) - i) * cnt[i-1]);
	cout << res << '\n';
}
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt = 1; std::cin >> tt;
	while (tt --> 0) solve();
}