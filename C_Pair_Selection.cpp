#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define order_set for additional functionality if needed
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool calc(double x, vector<pair<int, int>> &v, int k) {
    int n = v.size();
    vector<double> arr(n);

    // Calculate the difference based on the current x
    for (int i = 0; i < n; i++) {
        arr[i] = x * v[i].second - v[i].first;
    }

    // Sort the array to find the smallest k elements
    sort(arr.begin(), arr.end());

    // Calculate the sum of the smallest k elements
    double acc = 0.0;
    for (int i = 0; i < k; i++) {
        acc += arr[i];
    }

    // Check if the sum is <= 0
    return acc <= 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);

    // Input the values for v
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // Binary search for the answer
    double lo = 0.0, hi = 1e5; // Use a more reasonable lower bound
    int iterations = 70; // Number of iterations for binary search
    for (int i = 0; i < iterations; i++) {
        double mid = lo + (hi - lo) / 2;
        if (calc(mid, v, k)) {
            lo = mid; // Update the upper bound
        } else {
            hi = mid; // Update the lower bound
        }
    }

    // Print the result with high precision
    cout << setprecision(20) << hi << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // Uncomment the below line if multiple test cases are needed
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
