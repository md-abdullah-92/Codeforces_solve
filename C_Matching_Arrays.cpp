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
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n); 
    vector<int> b(n), ans(n),c(n); 

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        c[i]=a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    for (int i = n-x; i < n; i++) {
            ans[a[i].second] = b[j];
            j++;
    }
    for (int i = 0; i < n-x; i++) {
                ans[a[i].second] = b[j];
                j++;
        
    }

    int validCount = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] > ans[i]) {
            validCount++;
        }
    }

    if (validCount != x) {
        no;
        return;
    }

    yes;
    for (int kp : ans) {
        cout << kp << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
