#include <bits/stdc++.h>
#define int long long 
#define all(x) (x).begin(),(x).end()
using namespace std;
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m)), b(n,vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	vector<set<int>> row_a(n), col_a(m);
	vector<set<int>> row_b(n), col_b(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			row_a[i].insert(a[i][j]);
			row_b[i].insert(b[i][j]);
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			col_a[j].insert(a[i][j]);
			col_b[j].insert(b[i][j]);
		}
	}
	sort(all(row_a));
	sort(all(row_b));
	if (row_a != row_b) {
		cout << "NO\n";
		return;
	}
	sort(all(col_a));
	sort(all(col_b));
	if (col_a != col_b) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt; cin >> tt;
	while (tt --> 0) solve();
}
