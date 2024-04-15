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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int k = v[0];
    v[0] = 0;
    cout << k << " ";
    for (int i = 1; i < n; i++) {
        int mx = 0, p = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] && (__gcd(k, v[j]) >= mx)) {
                mx = __gcd(k, v[j]);
                p = j;
            }

        }
        cout << v[p] << " ";
        v[p] = 0;
        k = mx;
    }

    cout << endl;

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
