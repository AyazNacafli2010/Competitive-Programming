#include <bits/stdc++.h>
#define isz(x) ((int)(x.size()))
using namespace std;

void solve() {
    int x; cin >> x;
    string s{};
    while (x > 0) {
        if (x % 2 == 1)
            s += '1';
        else
            s += '0';
        x /= 2;
    }
	s += '0';
    int count1 = count(s.begin(), s.end(), '1');
    long long answ{};
    bool flag0 = true, flag1 = true;
    for (int i = 0; i < isz(s); i++) {
        if (count1 == 1 && flag0 == true && s[i] == '0') {
            answ += (1 << i);
            flag0 = false;
        }
        if (flag1 == true && s[i] == '1') {
            answ += (1 << i);
            flag1 = false;
        }
    }
    cout << answ << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1; cin >> tt;
    while (tt --> 0) solve();
    return 0;
}
