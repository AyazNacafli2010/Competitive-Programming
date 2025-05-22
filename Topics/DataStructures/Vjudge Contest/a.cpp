#include<bits/stdc++.h>
#define int int64_t
#define isz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	stack<int> one,zero;
	vector<int>ans(n);
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		if (s[i] == '1') {
			if (zero.empty()) {
				cnt++;
				ans[i] = cnt;
				one.push(cnt);
			}
			else {
				int last = zero.top();
				zero.pop();
				ans[i] = last;
				one.push(last);
			}
		}
		else {
			if (one.empty()) {
				cnt++;
				ans[i] = cnt;
				zero.push(cnt);
			}
			else {
				int last = one.top();
				one.pop();
				ans[i] = last;
				zero.push(last);
			}
		}
	}
	cout << cnt << '\n';
	for (auto it : ans)
		cout << it << ' ';
	cout << '\n';
}
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tt; cin >> tt;
	while (tt --> 0) solve();
}