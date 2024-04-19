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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n),v1(n);
    map<int, int> mp,mp1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int p = -1;
    int k = n;
    for (int i = 0; i < n; i++) {
        if (v[i] != v[0]) {
                k = min(k, i - p - 1);
                p = i;
            }
    }
    k = min(k, n - p - 1);
    if (k == n) {
        cout << -1 << endl;
    } else {
        cout << k << endl;
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