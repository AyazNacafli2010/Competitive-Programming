#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin >> s;
	int n = (int)s.size();
	int q; cin >> q;
	vector<set<int>> p(26);
	for (int i = 0; i < n; i++)
		p[s[i] - 'a'].insert(i);
	while (q --> 0){
		int type; cin >> type;
		if (type == 1){
			int pos; cin >> pos;
			pos--;
			char c; cin >> c;
			p[s[pos] - 'a'].erase(pos);
			s[pos] = c;
			p[s[pos] - 'a'].insert(pos);
		}
		else {
			int l, r; cin >> l >> r;
			l--, r--;
			int answ = 0;
			for (int i = 0; i < 26; i++) {
				auto id = p[i].lower_bound(l);
				if (id != (p[i]).end() && *id <= r)
					answ++;
			}
			cout << answ << '\n';
		}
	}
	return 0;
}