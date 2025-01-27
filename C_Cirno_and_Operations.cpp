#include <bits/stdc++.h>
using namespace std;

#define int long long
#define YES cout << "YES\n";
#define NO cout << "NO\n";

void solve() {
    int size;
    cin >> size;
    vector<int> v(size);
    int max_sum = 0;
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < size; i++) {
        max_sum += v[i];
    }
    while (v.size() > 1) {
        vector<int> df;
        int t = 0;
        for (size_t i = 1; i < v.size(); i++) {
            int k = v[i] - v[i - 1];
            df.push_back(k);
            t += k;
        }

        max_sum = max(max_sum, abs(t));
        v = df;
    }

    max_sum = max(max_sum, v.front());
    cout << max_sum << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
