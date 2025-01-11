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
    int n;
    cin >> n;

    if (n == 0) {  // Handle edge case where n = 0
        cout << 0 << endl;
        return;
    }

    vector<int> v1(n), v2(n);
    vector<int> ans,x;

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    int sum=0;

    for (int i = 0; i < n; i++) {
        ans.push_back(v1[i] + v2[i]);
        x.push_back(max(v1[i],v2[i]));
        sum+=x[i];
    }
    int mx_sum=LLONG_MIN;
    for (int i = 0; i < n; i++) {
        mx_sum = max(mx_sum,sum-x[i]+ans[i]);
    }

    cout << mx_sum << endl;
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
