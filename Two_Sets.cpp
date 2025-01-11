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
    int totalSum = (n * (n + 1)) / 2; // Sum of the first n natural numbers

    if (totalSum % 2 != 0) {
        no; // If the total sum is odd, it's impossible to divide into two equal subsets
        return;
    }

    yes; // The division is possible
    vector<int> v1, v2;

    int halfSum = totalSum / 2;
    for (int i = n; i >= 1; --i) {
        if (halfSum >= i) {
            v1.push_back(i);
            halfSum -= i;
        } else {
            v2.push_back(i);
        }
    }

    // Output the results
    cout << v1.size() << endl;
    for (int x : v1) cout << x << " ";
    cout << endl;

    cout << v2.size() << endl;
    for (int x : v2) cout << x << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T; // Uncomment this if there are multiple test cases
    while (T--) {
        solve();
    }

    return 0;
}
