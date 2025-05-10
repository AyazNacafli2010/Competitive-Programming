#include <bits/stdc++.h>
#define isz(x) (int)(x).size()

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

void solve() {
	int n;
	cin >> n;
	int a, b, mx1 = 0, mx2 = 0;
	for(int i = 0;i < n;i++){
		cin >> a >> b;
		mx1 = max(mx1,a);
		mx2 = max(mx2,b);
	}
	cout << (mx1 + mx2) * 2 << '\n';
	return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int t = 1; cin >> t;
	while(t--)
		solve();
	return 0;
}
