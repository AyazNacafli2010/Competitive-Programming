#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, t, a, b;
    cin >> n >> t >> a >> b;

    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];

    vector<int> pre(n + 1);
    for (int i = 0; i <= n; i++)
        pre[i] = (i == 0 ? 0 : pre[i - 1] + k[i]);

    int answ = 0, Time = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        Time += a;
        int diff = Time - t;
        sum = pre[i];
        if (diff > 0) {
            diff /= (a - b);
			sum -= pre[diff];
        }
        answ = max(answ, sum);
    }

    cout << answ;
}
