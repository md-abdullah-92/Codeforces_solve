#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

bool isright(const vector<int>& v, int n, int m, int k) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= m) break;
        else ans += (m - v[i]);
    }
    return ans <= k;
}

int binarySearch(const vector<int>& v, int n, int k) {
    int lo = 0, hi = 100000000000, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isright(v, n, mid, k)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = binarySearch(v, n, k);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
