#include <bits/stdc++.h>
#define int long long
#define isz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
using namespace std;
using pii = pair<int,int>;
void solve() {
	int n; cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++)
		cin >> a[i];
	sort(all(a));
	for (int i = 0; i < 2 * n - 1; i++) {
		int x = a[i] + a[2 * n - 1];
		int answ = x;
		vector<pii> res = [&]() {
			multiset<int> ms;
			vector<pii> cur;
			for (auto &it : a)
				ms.insert(it);
			for (int i = 0; i < n; i++) {
				auto in = ms.end();	
				in--;
				int Mx_element = *in;
				int Lk_element = x - Mx_element;
				ms.erase(in);
				auto in2 = ms.find(Lk_element);
				if (in2 == ms.end()) {
					cur.clear();
					return cur;
				}
				ms.erase(in2);
				cur.push_back({Mx_element,Lk_element});
				x = max(Mx_element,Lk_element);
			}
			return cur;	
		}();
		if (isz(res) > 0) {
			cout << "YES\n" << answ << '\n';
			for (auto [num1,num2] : res)
				cout << num1 << ' ' << num2 << '\n';
			return;
		}
	}
	cout << "NO\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) solve();
}
