#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int sum1 = 0, sum2 = 0, mn = 0, mx = 0, t = -1;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) != 1) {
            sum1 = sum2 = 0;
            t = i;
            continue;
        }
        sum1 = max(a[i], sum1 + a[i]);
        sum2 = min(a[i], sum2 + a[i]);

        mx = max(mx, sum1);
        mn = min(mn, sum2);
    }

    set<int> ans;
    for (int i = mn; i <= mx; i++) ans.insert(i);

    if (t != -1) {
        int local_mn = 1e10, local_mx = -1e10;
        int sum = 0;

        // Prefix sum from `who` to the left
        for (int i = t; i >= 0; i--) {
            sum += a[i];
            local_mn = min(local_mn, sum);
            local_mx = max(local_mx, sum);
        }

        sum = 0;

        // Suffix sum from `who` to the right
        for (int i = t; i < n; i++) {
            sum += a[i];
            local_mn = min(local_mn, sum);
            local_mx = max(local_mx, sum);
        }

        sum = 0;
        mx=0,mn=0;

        // Compute prefix sums from the left side up to `who - 1`
        for (int i = t - 1; i >= 0; i--) {
            sum += a[i];
            mn = min(mn, sum);
            mx = max(mx, sum);;
        }

        sum = 0;
        // Compute suffix sums from `who` to the right side
        for (int i = t; i < n; i++) {
            sum += a[i];

            // Calculate maximum and minimum sums using prefix data
            int mxs = sum + mx; // Max possible sum
            int mns = sum + mn;  // Min possible sum

            // Update local bounds
            local_mx = max(local_mx, mxs);
            local_mn = min(local_mn, mns);
        }


        for (int i = local_mn; i <= local_mx; i++) ans.insert(i);
    }

    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
    return;
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
