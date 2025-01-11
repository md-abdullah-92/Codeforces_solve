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
    int n, t, p;
    cin >> n >> t >> p;
    vector<pair<int, int>> v(n), v1(t);
    priority_queue<int> q;

    // Reading first list of intervals
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    // Reading second list of intervals
    for (int i = 0; i < t; i++) {
        cin >> v1[i].first >> v1[i].second;
    }

    // Sorting both lists by their first elements
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());

    int j = 0;    // Pointer for the second list
    int sum = 0;  // Sum of selected elements
    int ans = 0;  // Number of elements taken

    // Processing the first list
    for (int i = 0; i < n; i++) {
        // Add all elements from the second list whose start time is less than the current interval start time
        while (j < t && v1[j].first < v[i].first) {
            q.push(v1[j].second);
            j++;
        }

        // Calculate the required value for the current interval
        int required = v[i].second - v[i].first + 1;

        // Pick elements from the priority queue to satisfy the required sum
        while (!q.empty() && sum < required) {
            int top = q.top();
            q.pop();
            sum += top;
            ans++;
        }

        // If the required sum cannot be met, print -1 and return
        if (sum < required) {
            cout << -1 << endl;
            return;
        }
    }

    // Output the total number of elements used
    cout << ans << endl;
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
