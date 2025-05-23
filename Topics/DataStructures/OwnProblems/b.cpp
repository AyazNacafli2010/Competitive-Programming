#include <bits/stdc++.h>
#define int long long
#define isz(x) (int)x.size()
#define all(x) x.begin(),x.end()

main(){ 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::string s; std::cin >> s;
	int n = isz(s);
	if (n <= 3) {
		std::cout << "NO\n";
		return 0;
	}
	std::pair<int,int> first_ab = {0,0}, last_ba = {0,0};
	for (int i = 0; i < n-1; i++) {
		if (s[i] == 'A' && s[i+1] == 'B' && first_ab.first == 0 && first_ab.second == 0)
			first_ab = {(i+1), (i+2)};
		if (s[i] == 'B' && s[i+1] == 'A')
			last_ba = {(i+1), (i+2)};
	}
	if (first_ab.first != 0 && first_ab.second != 0 && last_ba.first != 0 && last_ba.second != 0 && first_ab.first != last_ba.second && first_ab.second != last_ba.first) {
		std::cout << "YES\n";
		return 0;
	}
	std::pair<int,int> first_ba = {0,0}, last_ab = {0,0};
	for (int i = 0; i < n-1; i++) {
		if (s[i] == 'B' && s[i+1] == 'A' && first_ba.first == 0 && first_ba.second == 0)
			first_ba = {(i+1), (i+2)};
		if (s[i] == 'A' && s[i+1] == 'B')
			last_ab = {(i+1), (i+2)};
	}
	if (first_ba.first != 0 && first_ba.second != 0 && last_ab.first != 0 && last_ab.second != 0 && first_ba.second != last_ab.first && last_ab.second != first_ba.first) {
		std::cout << "YES\n";
		return 0;
	}
	std::cout << "NO\n";
}