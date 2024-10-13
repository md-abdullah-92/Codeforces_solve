#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int p;
    cin >> p;
    
    vector<int> v(p);
    vector<int> prefix;
    for (int i = 0; i < p; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    // Fix dp size, initialize as 0
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    
    // Apply the difference matrix approach for the k x k submatrix updates
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            dp[i][j] += 1;
            dp[i + k][j] -= 1;
            dp[i][j + k] -= 1;
            dp[i + k][j + k] += 1;
        }
    }

    // Correct accumulation of the dp matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            prefix.push_back(dp[i][j]);
        }
    }

    sort(prefix.begin(), prefix.end(), greater<int>());
    
    // Ensure enough elements in the prefix array
    int ans = 0;
    for (int i = 0; i < min(p, (int)prefix.size()); i++) {
        ans += prefix[i] * v[i];
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
