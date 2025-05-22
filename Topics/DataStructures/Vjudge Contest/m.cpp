#include <bits/stdc++.h>
#define int long long 
#define all(x) x.begin(),x.end()

using namespace std;
void remax(int &a, int b) { 
	a = max(a,b); 
}
void solve() {
	int n, c; cin >> n >> c;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> pre(n+1), ans(n+1), mx_element(n+1);
	for (int i = 0; i <= n; i++) {
		pre[i] = (i == 0 ? 0 : pre[i-1] + a[i]);
		mx_element[i] = (i == 0 ? 0 : max(a[i],mx_element[i-1]));
	}
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		if (x == max(a[1]+c,mx_element[n]) && x > max(a[1]+c,mx_element[i-1])) {
			ans[i] = 0;
		} 
		else {
			x += pre[i-1] + c;
			if (x >= mx_element[n]) {
				ans[i] = i-1;
			} 
			else {
				ans[i] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt; cin >> tt;
	while (tt --> 0) solve();
}
