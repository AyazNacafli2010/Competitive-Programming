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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<string> v;
	for (int i = 0;i < n;i++){
		string temp = s;
		if(s[i] == '1') temp[i] = '0';
		else temp[i] = '1';
		v.push_back(temp);
	}
	int answ = 0;
	for(auto it : v){
		auto cnt = [&]() {
			int res = 0;
			for(auto c : it){
				if(c == '1') res++;
			}
			return res;
		};
		answ += cnt();
	}
	cout << answ << '\n';
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
