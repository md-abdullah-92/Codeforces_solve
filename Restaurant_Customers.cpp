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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 1});  // Mark the start of an interval
        v.push_back({y, -1}); // Mark the end of an interval
    }

    // Sort the events by time
    sort(v.begin(), v.end());

    int ans = 0, sum = 0;

    // Sweep line to find the maximum number of overlapping intervals
    for (auto &event : v) {
        sum += event.second;  // Add 1 for a start event, subtract 1 for an end event
        ans = max(ans, sum);  // Keep track of the maximum overlap
    }

    cout << ans << endl;  // Print the result
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // Uncomment the next line if you want multiple test cases
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
