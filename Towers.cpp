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
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto y = s.upper_bound(x); // Correctly declare `y` as an iterator
        if (y == s.end()) {       // Check if no element greater than `x` exists
            s.insert(x);
        } else {
            s.erase(y);           // Replace the element greater than `x`
            s.insert(x);
        }
    }
    cout << s.size() << endl; // Output the size of the multiset
    return;
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
