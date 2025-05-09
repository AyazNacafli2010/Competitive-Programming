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
    int n;
	cin >> n;
	string s;
	cin >> s;
	map<pair<char,char>,int> mp;
	for(int i = 0;i < n - 1;++i){
		mp[{s[i],s[i+1]}]++;
	}
	int Max = 0;
	char a1,a2;
	for(auto [x,y] : mp){
		if(y > Max){
			a1 = x.first;
			a2 = x.second;
			Max = y;
		}
	}
	cout << a1 << a2 << '\n';
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
