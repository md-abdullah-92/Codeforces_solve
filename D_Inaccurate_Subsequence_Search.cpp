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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    vector<int> a(m);
    unordered_map<int, int> target_count;
    unordered_map<int, int> window_count;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        target_count[a[i]]++;
    }

    int ans = 0;
    int count = 0; // to keep track of the number of matches in the current window

    for (int i = 0; i < n; i++) {
        if (target_count.count(v[i])) {
            window_count[v[i]]++;
            if (window_count[v[i]] <= target_count[v[i]]) {
                count++;
            }
        }

        if (i >= m) {
            int to_remove = v[i - m];
            if (target_count.count(to_remove)) {
                if (window_count[to_remove] <= target_count[to_remove]) {
                    count--;
                }
                window_count[to_remove]--;
            }
        }

        if (i >= m - 1 && count >= k) {
            ans++;
        }
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
