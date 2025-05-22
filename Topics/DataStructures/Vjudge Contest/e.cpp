#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		string s; cin >> s;
		vector<int> pre(n + 1);
		pre[0] = 0;
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i - 1] - '0');
		map<int,int> mp;
		mp[0] = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			ans += mp[pre[i] - i];
			mp[pre[i] - i]++;
		}
		cout << ans << '\n';
	}
}