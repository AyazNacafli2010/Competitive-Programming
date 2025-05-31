#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5; 
int trie[N][2], a[N], b[N];
int nextNode = 1;

void add(int n){
    int node = 0;
    for(int bt = 30 ; bt >= 0 ; bt--){
        int x = (n & (1 << bt)) > 0;
        if(!trie[node][x]) trie[node][x] = nextNode++;
        node = trie[node][x];
    }
}
int query(int n) {
	int node = 0, res = 0;
	for (int bt = 30; bt >= 0; bt--) {
		int x = (n & (1 << bt)) > 0;
		if (trie[node][x ^ 1]) {
			node = trie[node][x ^ 1];
			res |= (1<<bt);
		} else {
			node = trie[node][x];
		}
	}
	return res;
}
void solve() {
	int n; cin >> n;
	for (int i = 2; i <= n; i++) cin >> a[i];
	b[1] = 0;
	add(0);
	for (int i = 2; i <= n; i++) {
		b[i] = (b[i-1] ^ a[i]);
		add(b[i]);
	}
	int res;
	for (int i = 0; i <= n-1; i++) {
		if (query(i) == n-1) {
			res = i;
			break;
		}
	}
	for(int i = 1 ; i <= n ; i++)  cout << (res^b[i]) << ' ';
	cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int tt = 1;
	while (tt --> 0) solve();
    return 0;
}