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

// mod value (must be prime for Fermat's theorem to apply)
int mod = 1e9 + 7;
 vector<int>precalculation(1000005, 1);
 void pre()
 {
     precalculation[0] = 1;
     for (int i = 1; i < 1000005; i++) {
        precalculation[i] = (precalculation[i - 1] * i) % mod;
    }
 }

// Function to calculate modular exponentiation
int modpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

// Function to calculate modular inverse using Fermat's theorem
int modinv(int a, int m) {
    return modpow(a, m - 2, m);
}

// Function to calculate nCr % mod
int ncr(int n, int r) {
    if (r > n) {
        return 0;
    }
    int num = precalculation[n];
    int den = (precalculation[r] * precalculation[n - r]) % mod;
    return (num * modinv(den, mod)) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    int sum = 0;
   
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int p = (k + 1) / 2;
    int ans = 0;
    for (int i = p; i <= k; i++) {
        int x = ncr(sum, i);
        int y = ncr(n - sum, k - i);    
        ans = (ans + (x * y) % mod) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
