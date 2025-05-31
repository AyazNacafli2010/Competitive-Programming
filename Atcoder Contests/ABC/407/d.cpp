#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	unsigned H, W; cin >> H >> W;
	vector A(H, vector<unsigned long>(W));
	for (unsigned i = 0; i < H; i++)
		for (unsigned j = 0; j < W; j++)
			cin >> A[i][j];
	vector<unsigned> possible_domino{0};
	const unsigned domino_vertical = (1 << W) + 1, domino_horizontal = 3;
	for (unsigned i = 0, bit = 0; i < H; i++) {
		for (unsigned j = 0;j < W; j++, bit++) {
			vector<unsigned> temp;
			for (const auto b : possible_domino) {
				if (j + 1 < W && !(b & domino_horizontal << bit))
					temp.push_back(b | domino_horizontal << bit);
				if (i + 1 < H && !(b & domino_vertical << bit))
					temp.push_back(b | domino_vertical << bit);
			}
			ranges::move(temp, back_inserter(possible_domino));
		}
	}
	unsigned long answ = 0;
	for (auto b : possible_domino) {
		unsigned long cur = 0;
		for (unsigned i = 0, bit = 0; i < H; i++)
			for (unsigned j = 0; j < W; j++, bit++)
				if (1 & ~b >> bit)
					cur ^= A[i][j];
		answ = max(cur, answ);
	}
	cout << answ << '\n';
    return 0;
}