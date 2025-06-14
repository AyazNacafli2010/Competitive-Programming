#include <bits/stdc++.h>
#define long long long
using namespace std;
const long N = 2e5 + 5;
int a[N], dp2[N], dp1[N], answ[N];
void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		dp1[i] = dp2[i] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] > a[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
	for (int i = n-1; i >= 0; i--)
		for (int j = n-1; j > i; j--)
			if (a[i] > a[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
	for (int i = 0; i < n; i++)
		answ[i] = (dp1[i] + dp2[i]) - 1;
	cout << *max_element(answ, answ + n) << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}