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

int deg3(int x){
	int res = 0;
	while(x % 3 == 0){
		x/=3;
		res++;
	}
	return res;
}
void solve(int cs){
	int n; 
	cin >> n;
	vi a(n);
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		v.push_back({-deg3(a[i]),a[i]});
	}
	sort(v.begin(),v.end());
	for(auto [x,y] : v)
		cout << y << ' ';
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
