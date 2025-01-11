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

void solve()
{
    int t, n;
    cin >> t >> n;
    map<int, int> quantityMap;

    // Reading inputs and summing quantities for unique items
    for (int i = 0; i < n; i++) {
        int item, quantity;
        cin >> item >> quantity;
        quantityMap[item] += quantity;
    }

    // Extracting quantities and sorting in descending order
    vector<int> quantities;
    for (auto &entry : quantityMap) {
        quantities.push_back(entry.second);
    }
    sort(quantities.rbegin(), quantities.rend());

    // Calculating the answer
    int ans = 0;
    for (int i = 0; i < min(t, (int)quantities.size()); i++) {
        ans += quantities[i];
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
