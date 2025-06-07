#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define isz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5;
int cnt[N], ans[N], a[N];
vector<int> b[N];

main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i] % m]++;
		b[a[i] % m].push_back(i);
	}
	int k = n / m, answ = 0;
	set<int>st;
	for (int i = 0; i < m; i++)
		if (cnt[i] < k)
			st.insert(i);
	for (int i = 0; i < m; i++) {
		if (cnt[i] <= k) continue;
		if (cnt[i] > k) {
			int rem = cnt[i] - k;
			cnt[i] = k;
			for (int &j : b[i]) {
				rem--;
				auto it = st.lower_bound((i+1)%m);
				if (it == st.end())
					it = st.begin();
				int diff = (*it - i + m) % m;
				a[j] += diff;
				answ += diff;
				cnt[*it]++;
				if (cnt[*it] == k)
					st.erase(it);
				if (rem == 0)
					break;
			}
		}
	}
	cout << answ << '\n';
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}