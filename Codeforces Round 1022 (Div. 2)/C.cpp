#include <bits/stdc++.h>
#define isz(x) (int)(x).size()
#define int long long

using namespace std;

// using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(auto &it : a) cin >> it;
	a.push_back(0);
	int answ = 0,i = 0;
	while (i < n) {
		answ++;
		while (i < n && a[i] <= a[i + 1])
			i++;
		while (i < n && a[i] >= a[i + 1])
			i++;
	}
	cout << answ << '\n';
	return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt; cin >> tt;
	while (tt --> 0)
		solve();
	return 0;
}
