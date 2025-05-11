#include <bits/stdc++.h>
#define isz(x) (int)(x).size()
#define int long long

using namespace std;

// using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	for (auto &it : a) cin >> it;
	int odd = 0,even = 0,max_odd = -1;
	for (auto it : a){
		if (it % 2 == 1) {
			odd++;
			max_odd = max(max_odd,it);
		}
		else even++;
	}
	if (even == 0 || odd == 0) {
		cout << "0\n";
		return;
	}
	sort(a.begin(),a.end());
	int answ = 0;
	for (int i = 0;i < n;i++) {
		if (a[i] % 2 == 0){
			if (a[i] < max_odd) {
				a[i] += max_odd;
				max_odd = a[i];
				answ++;
			}
			else {
				max_odd += a[i];
				answ++;
				a[i] += max_odd;
				answ++;
				max_odd = a[i];
			}
		}
	}
	cout << min(even + 1, answ) <<  '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt; cin >> tt;
	while (tt --> 0)
		solve();
	return 0;
}
