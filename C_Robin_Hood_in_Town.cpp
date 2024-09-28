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

bool check_sum(vector<int> &v, int n, int sum)
{
   // int avg = sum / (2 * n);  // Calculate average based on sum and 2*n
    int p = 0;
    for (auto x : v) {
        if ((x*2*n) < sum) {
            p++;
        }
    }
    return 2*p <= n;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    if (n < 3) {
        cout << -1 << endl;
        return;
    }
    
    int start = 0, end =1e18;
    int ans = 1e18;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        if (check_sum(v, n, sum + mid)) {       
            start = mid + 1;
        } else {
            ans = min(ans, mid);
            end = mid - 1;  // Correct the binary search update
        }
    }
    
    cout << ans << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
