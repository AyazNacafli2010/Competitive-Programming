#include <bits/stdc++.h>
#define isz(x) (int)(x).size()

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

void solve() {
	int n, x;
	cin >> n >> x;
	for(int i = 0;i < n;i++)
		if(i != x)
			cout << i << ' ';
	if(x < n)
		cout << x;
	cout << '\n';
	return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	int t = 1; cin >> t;
	while(t--)
		solve();
	return 0;
}
