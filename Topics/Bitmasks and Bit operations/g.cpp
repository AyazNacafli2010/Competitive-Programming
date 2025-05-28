#include <bits/stdc++.h>
#define isz(x) ((int)(x.size()))
using namespace std;

void remax(long long &a, long long b) { a = max(a, b); }
void solve() {
    int n, k; 
	cin >> n >> k;
    string a, b; 
	cin >> a >> b;
    set<char> s;
    for (auto c : a)
        s.insert(c);
    vector<bool> ok(26, false);
    vector<int> v;
    for (char c : s)
		v.push_back(c - 'a');
    long long answ{};
    for (int i = 0; i < (1 << isz(v)); i++) {
        if (__builtin_popcount(i) > k)
            continue;
        fill(ok.begin(), ok.end(), false);
        for (int j = 0; j < isz(v); j++) {
            if ((1 << j) & i)
                ok[v[j]] = true;
		}
        int last = 0;
        long long res = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == b[j] || ok[a[j] - 'a'] == true)
                res += j - last + 1;
            else
                last = j + 1;
        }
        remax(answ, res);
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
