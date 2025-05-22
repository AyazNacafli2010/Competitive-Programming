#include <bits/stdc++.h>
#define int long long
using namespace std;
main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	vector<int> pre(n+1);
	for (int i = 0; i <= n; i++)
		pre[i] = (i == 0 ? 0 : pre[i-1] + a[i-1]);
	int Begin = 0, End = 0, answ = 0;
	set<int> s;
	s.insert(0);
	while (Begin < n) {
		while (End < n && s.count(pre[End+1]) == 0) {
			End++;
			s.insert(pre[End]);
		}
		answ += End - Begin;
		s.erase(pre[Begin]);
		Begin++;
	}
	cout << answ << '\n';
}