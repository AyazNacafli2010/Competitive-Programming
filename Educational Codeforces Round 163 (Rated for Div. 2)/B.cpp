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
// EDEDLER IKIREQEMLIDIR!!!
void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0;i < n;i++)
		cin >> a[i];
	vi v;
	v.push_back(a[n - 1]);
	for(int i = n - 2;i >= 0;i--){
		if(a[i] > v.back()){
			v.push_back(a[i] % 10);
			v.push_back(a[i] / 10);
		}
		else{
			v.push_back(a[i]);
		}
	}
	cout << ( ( is_sorted(v.rbegin(),v.rend()) )  ? "YES" : "NO") << '\n';
	return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt = 1; cin >> tt;
	while(tt--)
		solve();
	return 0;
}
