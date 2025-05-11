#pragma GCC optimize("O3")
#include "bits/stdc++.h"

#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*  Joe "Brown Bomber" Louis
	G.O.A.T of Heavyweight */

void solve(int cs){
	int n, k;
	cin >> n >> k;
	vi a(n);
	set<int> s;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(),a.end());
	if(k == 0 && a[0] > 1){
		cout << a[0] - 1 << '\n';
		return;
	}
	for(auto it : s){
		auto i = upper_bound(a.begin(),a.end(),it) - a.begin();
		if(i == k){
			cout << it << '\n';
			return;
		}
	}
	cout << "-1\n";
	return;
}
signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cerr << "Case : " << cs << '\n';
        solve(cs);
    }
	return 0;
}
