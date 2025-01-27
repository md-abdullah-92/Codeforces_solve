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

const int mod = 1e9 + 7;

int binpow(int x, int n, int mod) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod; // Fix: Correctly update x for squaring
        n /= 2;
    }
    return ans;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // Use binpow to compute b^c mod (mod-1)
    int x = binpow(b, c, mod - 1);

    // Use binpow to compute a^x mod mod
    int y = binpow(a, x, mod);

    cout << y << endl;
    return;
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
