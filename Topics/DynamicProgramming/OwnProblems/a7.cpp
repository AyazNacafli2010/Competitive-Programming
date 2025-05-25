#include <bits/stdc++.h>
void remax(int &a, int b) {
	a = std::max(a,b);
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n; std::cin >> n;
	std::vector<int> a(n+1,0);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::vector<int> left(n+1, 1), right(n+1, 1);
	left[0] = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > a[i-1])
			left[i] = left[i-1] + 1;
	right[n] = 1;
	for (int i = n - 1; i >= 1; i--)
		if (a[i+1] > a[i])
			right[i] = right[i+1] + 1;
	right[0] = 0;
	int answ{};
	for (int i = 1; i <= n; i++)
		remax(answ, left[i]);
	for (int i = 1; i <= n-2; i++)
		if (a[i+2] > a[i])
			remax(answ, left[i] + right[i+2]);
	std::cout << answ << std::endl;
	return 0;
}