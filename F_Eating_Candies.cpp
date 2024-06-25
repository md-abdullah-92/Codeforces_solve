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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0;
    int sum1 = 0, sum2 = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (sum1 == sum2) {
            ans = max(ans, i + (n - j - 1));
            if(i == j) break; // if they meet, avoid double counting the same candy
            sum1 += v[i];
            sum2 += v[j];
            i++;
            j--;
        } else if (sum1 < sum2) {
            sum1 += v[i];
            i++;
        } else {
            sum2 += v[j];
            j--;
        }
    }

    // Final check when i and j have crossed or met
    if (sum1 == sum2) {
        ans = max(ans, i + (n - j - 1));
    }

    cout << ans << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
