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
	sort(a.begin(),a.end());
	if(odd == 0 || even == 0) {
		cout << "0\n";
		return;
	}
	for(auto it : a){
		if(it % 2 == 0 && it < max_odd){
			max_odd += it;
		}
		else if(it % 2 == 0 && it > max_odd){
			even++;
			break;
		}
	}
	cout << even << '\n';
	return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt; cin >> tt;
	while (tt --> 0)
		solve();
	return 0;
}
