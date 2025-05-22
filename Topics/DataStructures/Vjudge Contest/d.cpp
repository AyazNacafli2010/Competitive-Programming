#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tt = 1; // cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int sum = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			pq.push(a[i]);
			while (sum < 0){
				sum -= pq.top();
				pq.pop();
			}
		}
		cout << pq.size() << '\n';
	}
}


