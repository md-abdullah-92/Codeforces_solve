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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ans;
    bool valid = true;
    for (int j = 0; j < n; j++) {
        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        
        for (int i = 1; i < m; i++) {
            if ((v[i] - v[i - 1]) != n) {
                valid=false;
                break;
            }
        }
        ans.push_back({v[0], j + 1});
    }
    if(!valid){
       cout<<"-1\n";
       return;
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x.second << " ";
    cout << endl;
    return;
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
