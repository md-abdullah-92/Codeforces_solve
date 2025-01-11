#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<long long> P;
        P.reserve(2 * n);
        for (auto x : a) P.push_back(x);
        for (auto x : b) P.push_back(x);
        sort(P.begin(), P.end());
        P.erase(unique(P.begin(), P.end()), P.end());
        
        long long max_earn = 0;
        for (auto P_val : P) {
            // lower_bound returns iterator to first >= P_val
            int lb_a = lower_bound(a.begin(), a.end(), P_val) - a.begin();
            int lb_b = lower_bound(b.begin(), b.end(), P_val) - b.begin();
            long long D = (long long)(lb_a) - (long long)(lb_b);
            if (D <= k) {
                long long buyers = n - lb_b;
                long long earn = P_val * buyers;
                if (earn > max_earn) max_earn = earn;
            }
        }
        cout << max_earn << "\n";
    }
    return 0;
}
