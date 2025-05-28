#include <bits/stdc++.h>
#define isz(x) (int)x.size()
using namespace std;

constexpr int sz = 2e5 + 5;

int a[sz], st[sz*4], n;

void build(int l,int r,int v) {
	if (l == r) {
		st[v] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, v<<1);
	build(mid+1, r, v<<1|1);
	st[v] = st[v<<1]|st[v<<1|1];
}
int get(int l,int r,int a,int b,int v) {
	if (l > b || a > r) return 0;
	if (a <= l && r <= b) return st[v];
	int mid = (l + r) / 2;
	return get(l, mid, a, b, v<<1)|get(mid+1, r, a, b, v<<1|1);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	build(1,n,1);
	int low = 0, high = n + 1;
	while (high - low > 1) {
		int mid = (low + high) / 2;
		auto check = [&]() {
			set<int> s;
			for (int i = 1; i <= n - mid + 1; i++)
				s.insert(get(1, n, i, i + mid - 1,1));
			if (isz(s) == 1) 
				return true;
			return false;
		};
		if (check())
			high = mid;
		else
			low = mid;
	}
	cout << high << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt --> 0) solve();
    return 0;
}
