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

//  Joe "Brown Bomber" Louis
//  G.O.A.T of Heavyweight

void solve(int cs){
    int n; cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++)
		cin >> a[i];
	map<int,int> dp;
	int last = 0,ans = 0;
	for(int i = 0;i < n;i++){
		dp[a[i]] = dp[a[i] - 1] + 1;
		if(ans < dp[a[i]]){
			ans =  dp[a[i]];
			last = a[i];
		}
	}
	vector<int> res;
	for(int i = n - 1;i >= 0;i--){
		if(last == a[i]){
			res.push_back(i);
			last--;
		}
	}
	reverse(res.begin(),res.end());
	cout << ans << '\n';
	for(auto it : res)
		cout << it + 1 << ' ';
	cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; // cin >> t;
	for(int cs = 1;cs <= t;cs++)
		solve(cs);
	return 0;
}
