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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    order_set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        s.insert(v[i]);
    }

    cout << *(s.find_by_order((k - 1) / 2)) << " ";

    // Slide the window
    for (int i = 0; i < n - k; i++) {
        s.erase(s.find(v[i]));         // Remove the element exiting the window
        s.insert(v[i + k]);           // Add the new element entering the window
        cout << *(s.find_by_order((k - 1) / 2)) << " ";
    }

    cout << "\n";
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
