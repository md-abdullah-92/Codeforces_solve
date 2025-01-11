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

void solve() {
    int n, q;
    cin >> n >> q;

    deque<int> d;
    int maxValue = -1, maxIndex = -1;

    // Reading the deque and finding the maximum value
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.push_back(x);
        if (x > maxValue) {
            maxValue = x;
            maxIndex = i;
        }
    }

    map<int, pair<int, int>> precomputedResults;

    // Simulating until the max value reaches the front
    for (int i = 0; i < maxIndex; i++) {
        int first = d.front();
        d.pop_front();
        int second = d.front();
        d.pop_front();

        precomputedResults[i + 1] = {first, second};

        if (first > second) {
            d.push_front(first);
            d.push_back(second);
        } else {
            d.push_front(second);
            d.push_back(first);
        }
    }

    vector<int> cycle;
    while (!d.empty()) {
        cycle.push_back(d.front());
        d.pop_front();
    }

    // Processing the queries
    for (int i = 0; i < q; i++) {
        int m_j;
        cin >> m_j;

        if (m_j <= maxIndex) {
            cout << precomputedResults[m_j].first << " " << precomputedResults[m_j].second << '\n';
        } else {
            cout << maxValue << " " << cycle[(m_j - maxIndex - 1) % (n - 1) + 1] << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // Uncomment below line to allow multiple test cases
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
