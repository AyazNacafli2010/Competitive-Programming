#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> v1, v2;
	int part1 = n / 2;
	for (int i = 0; i < (1 << part1); i++) {
		int sum = 0;
		for (int j = 0; j < n / 2; j++)
			if ((1<<j)&i)
				sum = (sum + a[j]) % m;
		v1.push_back(sum);
	}
	int other = n - part1;
	for (int i = 0; i < (1 << other); i++) {
		int sum = 0;
		for (int j = 0; j < other; j++)
			if ((1<<j)&i)
				sum = (sum + a[j+part1]) % m;
		v2.push_back(sum);
	}
	sort(v2.begin(), v2.end());
	int answ = 0;
	for (auto &it : v1) {
		int need = m - it;
		auto i = lower_bound(v2.begin(),v2.end(),need);
		if (i != v2.begin()) {
			i--;
			answ = max(answ, (*i + it) % m);
		} else {
			answ = max(answ, (v2.back() + it) % m);
		}
	}
	cout << answ << '\n';
    return 0;
}