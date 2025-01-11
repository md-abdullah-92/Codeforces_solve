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
    vector<int> v(n);

    // Input the array
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sum1 = 0, sum2 = 0, ans = 0;
    int i = -1, j = n;

    // Two-pointer approach to find the maximum equal sum
    while (i < j) {
        if (sum1 < sum2) {
            i++;
            sum1 += v[i];
        } else if (sum1 > sum2) {
            j--;
            sum2 += v[j];
        } else {
            // Update the answer and move both pointers
            i++;
            j--;
            ans = sum1;
            sum1 += v[i];
            sum2 += v[j];
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // Uncomment the line below if there are multiple test cases
    // cin >> T;

    while (T--) {
        solve();
    }
    return 0;
}
