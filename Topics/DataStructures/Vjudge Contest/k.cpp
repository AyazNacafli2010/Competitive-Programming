#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end() 
#define int long long 
using namespace std;
main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int sum = accumulate(all(a),0LL);
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	int block = sum / 3;
	vector<int> pre(n+1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + a[i];
	int cnt = 0, answ = 0;
	for (int i = 1; i < n; i++) {
		if (pre[i] == block * 2)
			answ += cnt;
		if (pre[i] == block)
			cnt++;
	}
	cout << answ << '\n';
}