#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    unordered_map<string, int> countMap;

    // Read strings and populate the count map
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        countMap[v[i]]++;
    }

    long long ans = 0;

    // Check each string and generate its variants
    for (const string& s : v) {
        countMap[s]--;  // Decrement the count of the current string

        // Generate all single character variations
        for (int i = 0; i < 2; ++i) {
            char originalChar = s[i];
            for (char c = 'a'; c <= 'k'; ++c) {
                if (c != originalChar) {
                    string variant = s;
                    variant[i] = c;
                    ans += countMap[variant];
                }
            }
        }

        // Restore the count of the current string
        countMap[s]++;
    }

    cout << ans /2<< endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
