#include <bits/stdc++.h>
#define int long long
#define isz(x) (int)x.size()
#define all(x) x.begin(),x.end()

main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m; std::cin >> n >> m;
	std::string s, t; std::cin >> s >> t;
	std::map<char, std::vector<int>> mp;
	for (int i = 0; i < n; i++) {
		mp[s[i]].push_back(i);
	}
	std::vector<int> left(m), right(m);
	int h = -1,answ = 0;
	for (int i = 0; i < m; i++) {
		auto k = std::upper_bound(mp[t[i]].begin(),mp[t[i]].end(), h) - mp[t[i]].begin();
		left[i] = mp[t[i]][k];
		h = mp[t[i]][k];
	}
	for (auto &[_,y] : mp) {
		for (auto &x : y) {
			x = -x;
		}
		std::sort(all(y));
	}
	h = -(int)1e18L;
	for (int i = m-1; i >= 0; i--) {
		auto k = std::upper_bound(mp[t[i]].begin(),mp[t[i]].end(), h) - mp[t[i]].begin();
		right[i] = -mp[t[i]][k];	
		h = mp[t[i]][k];		
	}
	for (int i = 0; i < m - 1;i++) {
		answ = std::max(answ, right[i+1] - left[i]);
	}
	std::cout << answ;
}