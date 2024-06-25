#include <bits/stdc++.h>
using namespace std;

#define int long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    
    int ans = 0;
    if (x == 0) {
        // Special case when x is 0, count pairs of identical elements
        for (auto& entry : mp) {
            int count = entry.second;
            ans += (count * (count - 1)) / 2;
        }
    } else {
        // General case for x != 0
        for (int i = 0; i < n; i++) {
            ans += mp[v[i] ^ x];
        }
        ans /= 2; // Each pair is counted twice
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
