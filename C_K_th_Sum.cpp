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

bool isvalid(int x, int k, vector<int>& a, vector<int>& b) {
    int cnt = 0;
    for (int xp : a) {
        if (xp < x){ 
        cnt += lower_bound(b.begin(), b.end(), x - xp) - b.begin();
        if (cnt >= k) return false; // Early exit if `cnt` exceeds or equals `k`.
        }
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end()); // Sorting `b` only once outside the loop for efficiency.

    int lo = 1, hi = 1e10, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isvalid(mid, k, a, b)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
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
