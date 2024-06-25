#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;

    vector<pair<int, int>> operations(c);
    vector<int> lengths(c + 1);
    lengths[0] = n;

    for (int i = 0; i < c; ++i) {
        int l, r;
        cin >> l >> r;
        operations[i] = {l - 1, r - 1};
        lengths[i + 1] = lengths[i] + (r - l + 1);
    }

    while (q--) {
        int k;
        cin >> k;
        --k;

        for (int i = c; i > 0; --i) {
            if (k >= lengths[i - 1]) {
                int offset = k - lengths[i - 1];
                k = operations[i - 1].first + offset;
            }
        }

        cout << s[k] << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
