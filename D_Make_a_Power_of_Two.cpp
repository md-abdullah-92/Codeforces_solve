#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int unsigned long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    string n;
    cin >> n;
    int p = 1;
    int ans = n.length()+1;
    for (int i = 0; i <= 62; i++) {
        string s = to_string(p);
        int r = 0;
        int j = 0, k = 0;
        while (s.length() > j && n.length() > k) {
            if (s[j] == n[k]) {
                j++;
                r++;
                k++;
            } else {
                k++;
            }
        }
        ans = min(ans, (s.length() - r + n.length() - r));
        p *= 2;
    }
    cout << ans <<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
