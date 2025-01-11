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
    int n;
    cin >> n;
    vector<int> v(30, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 30; j++) {
            if (x & (1LL << j)) { // Corrected condition to check if j-th bit is set in x
                v[j]++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < 30; j++) {
            if (v[j] > 0) { // Only use bits that are still available
                cur |= (1LL << j); // Add the j-th bit to cur
                v[j]--;
            }
        }
        ans += cur * cur; // Add the square of cur to the answer
    }

    cout << ans << "\n";
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
