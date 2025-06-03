#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

const int maxBit = 20;

main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> bitCnt(21, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int bit = 0; bit <= maxBit; bit++)
			bitCnt[bit] += x >> bit & 1;
	}
	int answ = 0;
	for (int i = 0; i < n; i++) {
		int b = 0;
		for (int bit = 0; bit <= maxBit; bit++)
			b |= (i < bitCnt[bit]) << bit;
		answ += b*b;
	}
	cout << answ << '\n';
	return 0;
}
