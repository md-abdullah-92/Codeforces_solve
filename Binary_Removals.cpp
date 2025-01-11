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
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    int zeros = 0;
    int inversions = 0;

    // Count zeros and calculate inversions
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            zeros++;
        } else {
            inversions += zeros;
        }
    }

    // Check conditions
    if (k == 0) {
        // Handle division by zero case
        cout << "2\n";
    } else if (inversions <= x && inversions % k == 0) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
