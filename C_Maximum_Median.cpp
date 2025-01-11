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

int x, k;

// Function to check if it's possible to make the median `val` or more by using at most `k` increments
bool canMakeMedian(vector<int> &v, int val) {
    int count = 0;
    for (int i = x; i < v.size(); i++) {
        count += max(val - v[i], 0LL);
        if(count>k) return false;
    }
    return count <= k;
}

void solve() {
    int n;
    cin >> n >> k;
    vector<int> v(n);

    // Reading the input array
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Sort the array
    sort(v.begin(), v.end());

    // Median index
    x = n / 2;

    // Binary search to find the maximum possible median
    int l = v[x], h = 1e10, ans = 0;
    while (l <= h) {
        int mid = l + (h - l) / 2;  // To avoid overflow
        if (canMakeMedian(v, mid)) {
            ans = mid; // Update the answer if valid
            l = mid + 1; // Try for a higher value
        } else {
            h = mid - 1; // Try for a lower value
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T = 1;
    // Uncomment below line to handle multiple test cases
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
