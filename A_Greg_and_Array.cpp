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

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> v(n + 2, 0); // Extend size to handle prefix-sum boundary
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // Process updates
    while (m--) {
        int x, y, d;
        cin >> x >> y >> d;
        v[x] += d;
        v[y + 1] -= d; // Correctly decrement the value at (y+1)
    }

    // Compute the prefix sum
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        cout<<v[i]<<" ";
    }

    // Process queries
    while (t--) {
        int x, y;
        cin >> x >> y;
        cout << v[y] - v[x - 1] << " ";
    }

    cout << "\n"; // Add a newline at the end for cleaner output
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T; // Uncomment if multiple test cases are needed
    while (T--) {
        solve();
    }
    return 0;
}
