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

const int MOD = 1000000007;

// Function to compute x^y % p in O(log y)
int mod_exp(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to find modular inverse of a under modulo p
// using Fermat's little theorem
int mod_inverse(int a, int p) {
    return mod_exp(a, p - 2, p);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    int sum = 0;
    int ans = 0;
    int q = ((n - 1) * n) / 2;  // q is the divisor

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans = (ans + ((sum * v[i]) % MOD)) % MOD;
        sum = (sum + v[i]) % MOD;
    }

    // Compute modular inverse of q under MOD
    int q_inv = mod_inverse(q, MOD);
    
    // Multiply ans by the modular inverse of q
    ans = (ans * q_inv) % MOD;
    
    cout << ans << endl;
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
