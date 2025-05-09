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
	int n, k;
	cin >> n >> k;
	while(k > 0){
		if(n % 10 != 0)
			n--;
		else
			n /= 10;
		k--;
	}
	cout << n << '\n';
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
