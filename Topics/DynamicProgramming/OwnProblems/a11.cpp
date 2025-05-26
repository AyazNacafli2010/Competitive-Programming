// A. Did We Get Everything Covered?
#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, m, k; 
	cin >> n >> k >> m;
	string s; cin >> s;
	vector<bool> found(k,false);
	int cnt = 0;
	string res;
	for (auto c : s) {
		if((int)res.size() == n) {
			break;
		}
		cnt += (!found[c - 'a']);
		found[c - 'a'] = true;
		if (cnt == k) {
			fill(found.begin(), found.end(), false);
			cnt = 0;
			res += c;
		}
	}
	if ((int)res.size() == n) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	for (int i = 0; i < k; i++)
		if (found[i] == false)
			while((int)res.size() < n)
				res += (char)(i + 'a');
	cout << res << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt --> 0) 
		solve();
	return 0;
}