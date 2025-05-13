#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k; cin >> n >> k;
	int low = 0,high = (int)1e18L+1;
	// low <= answer < high
	while (high - low > 1) {
		int mid = (low + high) / 2;
		auto cnt = [&]() {
			int res = 0, p = 0;
			while (mid / pow(k,p) > 0) {
				res += (mid / pow(k,p));
				p++;
			}
			return res;
		};
		if (cnt() >= n)
			high = mid;
		else 
			low = mid;
	}
	cout << high << ' ';
}
