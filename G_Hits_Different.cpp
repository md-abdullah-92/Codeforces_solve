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

constexpr int MAX_SIDE = 1500;
int a[MAX_SIDE + 1][MAX_SIDE + 1];
int ans[MAX_SIDE * (MAX_SIDE + 1) / 2 + 1];

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int curr = 1;

    // Precompute all values
    for (int i = 1; i <= MAX_SIDE; i++) {
        for (int j = 1; j <= i; j++) {
            int x = j, y = i - j + 1;
            a[x][y] = a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1] + curr * curr;
            ans[curr] = a[x][y];
            curr++;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
