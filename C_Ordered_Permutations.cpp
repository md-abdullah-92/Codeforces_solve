#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Macros and utility definitions
#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
// Definition of an ordered set using policy-based data structures
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    // Input variables
    int n;
    long long k;
    cin >> n >> k;

    // Vectors to hold numbers for output
    vector<int> a, b;

    // If n is small (<=60), check if k exceeds the maximum possible permutations (2^(n-1))
    if (n <= 60 && (1ll << (n - 1)) < k) {
        cout << -1 << endl; // Impossible case
        return;
    }

    k--; // Decrement k to make it 0-based

    // Vector `d` will store the binary representation of k
    vector<int> d;
    while (k) {
        d.push_back(k % 2); // Extract least significant bit
        k /= 2; // Shift right by 1 bit
    }

    // Pad the binary representation to size n-1 with zeros
    while (d.size() < n - 1) 
        d.push_back(0);

    // Traverse `d` to construct sequences `a` and `b`
    for (int i = n - 2, j = 1; i >= 0; i--, j++) {
        if (d[i] == 0) 
            a.push_back(j); // Append to `a` for binary 0
        else 
            b.push_back(j); // Append to `b` for binary 1
    }

    // Reverse vector `b` to maintain proper order
    reverse(b.begin(), b.end());

    // Output sequence: first `a`, then `n`, then `b`
    for (int i : a) 
        cout << i << ' ';
    cout << n << ' ';
    for (int i : b) 
        cout << i << ' ';
    cout << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}
