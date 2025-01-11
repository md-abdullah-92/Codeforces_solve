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
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Custom sorting based on x + y < y + x
    sort(v.begin(), v.end(), [](const string &x, const string &y) {
        return x + y < y + x;
    });

    // Concatenate sorted strings
    string result;
    for (const string &s : v) {
        result += s;
    }

    // Output the result
    cout << result << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T; // Read number of test cases
    while (T--) {
        solve();
    }
    return 0;
}
