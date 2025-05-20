#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct seg {
	int len, l, r;
	bool operator<(const seg &other) const {
		if (len != other.len) return len < other.len;
		return l > other.l;
	}
};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector<int> v(n + 1,0);
		priority_queue<seg> pq;
		pq.push({n, 1, n});
		for (int i = 1; i <= n; i++) {
			seg x = pq.top();
			pq.pop();
			if ((x.r - x.l + 1) % 2 == 1) {
				int mid = (x.r + x.l) / 2;
				v[mid] = i;
				// i1 = (mid - 1) - x.l + 1
				pq.push({(mid - 1) - x.l + 1, x.l, mid - 1});
				pq.push({x.r - (mid + 1) + 1, mid + 1, x.r});
			}
			else {
				int mid = (x.r + x.l - 1) / 2;
				v[mid] = i;
				pq.push({(mid - 1) - x.l + 1, x.l, mid - 1});
				pq.push({x.r - (mid + 1) + 1, mid + 1, x.r});
			}
		}
		for (int i = 1; i <= n; i++) 
			cout << v[i] << ' ';
		cout << '\n';
	}
}


