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
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<bool> visited(n + 1, false);
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store cycle sizes

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int x = i, cycle_size = 0;
            while (!visited[x]) {
                visited[x] = true;
                x = v[x - 1];
                cycle_size++;
            }
            pq.push(cycle_size);
        }
    }

    if (pq.size() == 1) {
        cout << 0 << endl;
        return;
    }

    int total_cost = 0;

    // Merge cycles using priority queue
    while (pq.size() > 1) {
        int c1 = pq.top();
        pq.pop();
        int c2 = pq.top();
        pq.pop();
        int merge_cost = c1 + c2;
        total_cost += merge_cost;
        pq.push(c1 + c2);
    }

    cout << total_cost << endl;

    return;
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
