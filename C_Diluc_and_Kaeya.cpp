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
    string s;
    cin >> s;

    // Vector to store prefix sums of 'D' and 'K'
    vector<pair<int, int>> v(n + 1);
    v[0] = {0, 0}; // Initialize the first element

    // Compute prefix sums
    for (int i = 0; i < n; i++) {
        v[i + 1].first = v[i].first + (s[i] == 'D');
        v[i + 1].second = v[i].second + (s[i] == 'K');
    }

    // Map to store the count of each normalized pair
    map<pair<int, int>, int> freq;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        int x = v[i].first;
        int y = v[i].second;

        // Normalize the pair (x, y) by dividing by their GCD
        int g = __gcd(x, y);
        x /= g;
        y /= g;

        // Increment the count for the normalized pair
        freq[{x, y}]++;

        // Add the current count to the result
        ans.push_back(freq[{x, y}]);
    }

    // Print the result
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
