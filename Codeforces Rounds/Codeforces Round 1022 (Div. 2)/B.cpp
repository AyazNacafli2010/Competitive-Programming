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
	int n, k;
	cin >> n >> k;
	int cntOne =  __builtin_popcount(k);
	if (cntOne >= n) cout << k << '\n';
	else if ((n - cntOne) % 2 == 0) cout << n - cntOne + k << '\n';
	else {
		if (k > 1) cout << n - cntOne + k + 1 << '\n';
		else if (k == 0) {
			if(n == 1) cout << "-1\n";
			else cout << n + 3 << '\n';
		}
		else cout << n + 3 << '\n';
	}
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
