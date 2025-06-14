// C. Divisibility by Eight
#include <bits/stdc++.h>
#define isz(x) (int)(x.size())
main() {
	std::string s; std::cin >> s;
	int n = isz(s);
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) 
		a[i] = s[i] - '0';
	for (int i = 0; i < n; i++) {
		if (a[i] % 8 == 0) {
			std::cout << "YES\n";
			std::cout << a[i];
			return 0;
		}
		for (int j = i + 1; j < n; j++) {
			if ((a[i]*10 + a[j]) % 8 == 0) {
				std::cout << "YES\n";
				std::cout << a[i] << a[j];
				return 0;
			}
			for (int k = j + 1; k < n; k++) {
				if ((a[i]*100 + a[j]*10 + a[k]) % 8 == 0) {
					std::cout << "YES\n";
					std::cout << a[i] << a[j] << a[k];
					return 0;
				}
			}
		}
	}
	std::cout << "NO\n";
}