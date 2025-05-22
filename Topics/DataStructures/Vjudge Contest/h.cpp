#include <bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
#define isz(x) (int)(x.size())
using namespace std;
main(){
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n), t(n);
	vector<int> group[4];
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> a[i] >> b[i];
		if (a[i] == 0 && b[i] == 0) group[0].push_back(t[i]);
		if (a[i] == 1 && b[i] == 0) group[1].push_back(t[i]);
		if (a[i] == 0 && b[i] == 1) group[2].push_back(t[i]);
		if (a[i] == 1 && b[i] == 1) group[3].push_back(t[i]);
	}
	vector<int> sum[4];
	for (int i = 0; i < 4; i++){
		sort(all(group[i]));
		sum[i].push_back(0);
		for (auto &it : group[i])
			sum[i].push_back(it + sum[i].back());
	}
	int answ = (int)1e18L;
	for (int cnt = 0; cnt <= min(k, isz(group[3])); cnt++) {
		if (k - cnt <= isz(group[1]) && k - cnt <= isz(group[2])) {
			answ = min(answ, sum[3][cnt] + sum[1][k - cnt] + sum[2][k - cnt]); 
		}
	}
	cout << (answ == (int)1e18L ? -1 : answ) << '\n';
}