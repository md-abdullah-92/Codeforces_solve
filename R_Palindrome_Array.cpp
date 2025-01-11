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

// Function to check if the array is a palindrome using recursion
bool func(int i, int n, const vector<int>& v) {
    if (n - 2 * i <= 1) {
        return v[i] == v[n - i];
    }
    return (v[i] == v[n - i]) && func(i + 1, n, v);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);

    // Reading the input array
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Check if the array is a palindrome
    if (func(0, n - 1, v)) {
        yes;
    } else {
        no;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // Uncomment the next line to take multiple test cases
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
