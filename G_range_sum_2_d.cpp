#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Maximum possible dimensions for the 2D arrays


void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    int forest[n+1][m+1];
    int tree_pref[n+1][m+1];
    // Initialize the forest array
    memset(forest, 0, sizeof(forest));
    memset(tree_pref, 0, sizeof(tree_pref));

    // Input forest values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            forest[i][j] = x;
        }
    }

    // Build the prefix sum array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tree_pref[i][j] = forest[i][j] 
                            + tree_pref[i - 1][j] 
                            + tree_pref[i][j - 1] 
                            - tree_pref[i - 1][j - 1];
        }
    }

    // Process queries
    for (int q = 0; q < t; q++) {
        int from_row, to_row, from_col, to_col;
        cin >> from_row >> from_col >> to_row >> to_col;

        // Calculate the sum using the prefix sum array
        cout << tree_pref[to_row][to_col] 
             - tree_pref[from_row - 1][to_col] 
             - tree_pref[to_row][from_col - 1] 
             + tree_pref[from_row - 1][from_col - 1]
             << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
