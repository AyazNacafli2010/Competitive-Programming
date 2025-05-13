#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, s; cin >> n >> s;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	int low = 0,high = n + 1,best = 0;
	while (high - low > 1){
		int mid = (low + high) / 2;
		auto Sum = [&]() {
			vector<int> temp;
			for (int i = 0;i < n;i++){
				temp.push_back(a[i].first + a[i].second * mid);
			}
			sort(temp.begin(),temp.end());
			int sum = 0;
			for (int i = 0;i < mid;i++)
				sum += temp[i];
			return sum;
		};
		if (Sum() <= s){
			low = mid;
			best = Sum();
		}
		else 
			high = mid;
	}
	cout << low << ' ' << best << '\n';
}
