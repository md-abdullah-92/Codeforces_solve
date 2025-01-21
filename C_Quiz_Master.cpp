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

const int N = 1e5 + 10;

vector<int> factor[N];

// Precomputing all factors for numbers up to 1e5
void precompute_factors() {
    for (int i = 1; i <= 1e5; i++) {
        for (int j = i; j <= 1e5; j += i) {
            factor[j].push_back(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = -1;
    int i = 0, j = 0;
    int cnt = 0;

    while (j < n) {
        // Add factors of v[j] to the map and update cnt
        for (int x : factor[v[j]]) {
            if (x > m) break;
            if (++mp[x] == 1) cnt++;
        }

        // Shrink the window while all m factors are present
        while (cnt == m) {
            ans = (ans == -1 ? (v[j] - v[i]) : min(ans, v[j] - v[i]));

            // Remove factors of v[i] from the map and update cnt
            for (int x : factor[v[i]]) {
                if (x > m) break;
                if (--mp[x] == 0) cnt--;
            }
            i++;
        }

        j++;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    precompute_factors();

    while (T--) {
        solve();
    }

    return 0;
}
