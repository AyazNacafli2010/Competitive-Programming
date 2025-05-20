#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
#define isz(x) (int)(x.size())

using namespace std;

using pii = pair<int,int>;
void solve(){
	int n, m; cin >> n >> m;
	vector<int> l(m), r(m);
	for (int i = 0; i < m; i++) 
		cin >> l[i] >> r[i];
	int qs; cin >> qs;
	vector<int> q(qs);
	for (int i = 0; i < qs; i++) 
		cin >> q[i];
	int low = 0, high = qs + 1;
	bool answ = false;
	while (high - low > 1){
		int mid = (high + low) / 2;
		bool ok = false;
		vector<int> v(n, 0), pre(n + 1, 0);
		for (int i = 0; i < mid; i++) v[q[i] - 1] = 1;
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + v[i - 1];
		for (int i = 0; i < m; i++){
			int len = r[i] - l[i] + 1;
			if (2 * (pre[r[i]] - pre[l[i] - 1]) > len)
				ok = true;
		}
		if (ok == true)
			high = mid,answ = true;
		else
			low = mid;
	}
	cout << (answ ? high : -1) << '\n';
}
main(){
	int tt = 1; cin >> tt;
	while (tt --> 0) solve();
}