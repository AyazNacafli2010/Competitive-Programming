#include <bits/stdc++.h>
#define isz(x) (int)(x).size()
#define int long long 

using namespace std;

using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

void solve() {
	int n; 
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int res = (int)1e18L;
	for(int i = 0; i < n; i++){
		int mGt = 0;
		for(int j = i;j < n;j++)
			if(a[j] > a[i]) mGt++;
		res = min(res, i + mGt);
	}
	cout << res << '\n';
	return;
}
main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int t = 1; cin >> t;
	while(t--)
		solve();
}
