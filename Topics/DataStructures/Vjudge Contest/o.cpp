#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[1002][1002], pre[1002][1002];
void fix() {
    for (int i = 0; i <= 1001; i++)
        for (int j = 0; j <= 1001; j++)
            pre[i][j] = a[i][j] = 0;
}
void solve() {
	int n, q; cin >> n >> q;
	fix();
	for (int i = 0; i < n; i++) {
		int h, w; cin >> h >> w;
		a[h][w] += h * w;
	}
	for (int i = 1; i <= 1000; i++) 
		for (int j = 1;j <= 1000;j++)
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
	while (q--) {
		int h1, w1, h2, w2; 
		cin >> h1 >> w1 >> h2 >> w2;
		cout << pre[h2-1][w2-1] + pre[h1][w1] - pre[h1][w2-1] - pre[h2-1][w1] << '\n';
	}
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt; cin >> tt;
	while (tt --> 0) solve();
}