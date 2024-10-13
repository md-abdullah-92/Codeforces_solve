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

int getSum(int start, int len) {
    int end = start + len - 1;
    return (end * (end + 1)) / 2 - (start * (start - 1)) / 2;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int p = n + k - 1;
    int sum = getSum(k, n); // Sum of range [k, k+n-1]
    
    int ans = LLONG_MAX; // To store the minimum difference

    // Binary search for an optimal point to minimize the difference
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int cum = getSum(k, mid + 1); // Cumulative sum up to mid
        int remainingSum = sum - cum;
        int diff = abs(cum - remainingSum);

        ans = min(ans, diff);

        if (cum > remainingSum) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
