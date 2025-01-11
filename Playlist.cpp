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
    vector<int> v(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int i = 0, j = 0, ans = 0;

    while (j < n) {
        mp[v[j]]++;

        // If we encounter a duplicate, shrink the window from the left
        while (mp[v[j]] > 1) {
            mp[v[i]]--;
            i++;
        }

        // Update the answer with the current window size
        ans = max(ans, j - i + 1);

        j++;
    }

    cout << ans << endl;
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
