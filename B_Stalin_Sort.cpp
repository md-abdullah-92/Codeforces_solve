#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<long long, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].first += i - 1;
        a[i].second = i - 1;
    }
    
    a[1].first = 0;
    sort(a.begin(), a.end());
    
    map<long long, bool> dp;
    dp[n] = true;
    
    for (int i = 2; i <= n; i++) {
        if (dp[a[i].first]) {
            dp[a[i].first + a[i].second] = true;
        }
    }
    
    long long ans = 0;
    for (const auto& [x, y] : dp) {
        if (y) {
            ans = x;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tests;
    cin >> tests;
    
    while (tests--) {
        solve();
    }
    
    return 0;
}