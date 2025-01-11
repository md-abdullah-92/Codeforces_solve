#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int inf = 1e18;

template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }

    vector<vector<int>> next(n, vector<int>(m));
    for (int k = 0; k < m; k++) {
        int r = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            while (r < n && sum + v1[r] <= v2[k]) {
                sum += v1[r++];
            }
            next[i][k] = r;
            sum -= v1[i];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m, inf));
    dp[0][0] = 0;

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < n; i++) {
                dp[next[i][k]][k] = min(dp[next[i][k]][k], dp[i][k] + m - k - 1);
            if (k < m - 1) {
                dp[i][k + 1] = min(dp[i][k + 1], dp[i][k]);
            }
        }
    }

    int ans = inf;
    for (int k = 0; k < m; k++) {
        ans = min(ans, dp[n][k]);
    }

    if (ans == inf) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
