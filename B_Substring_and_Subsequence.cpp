#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isSubsequence(const string& sub, const string& s) {
    int m = sub.length(), n = s.length();
    int j = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (sub[j] == s[i]) {
            j++;
        }
    }
    return j == m;
}

int longestSubsequenceAsSubstring(const string& s, const string& k) {
    int m = k.length();
    int maxLength = 0;

    for (int len = 1; len <= m; len++) {
        for (int i = 0; i <= m - len; i++) {
            string sub = k.substr(i, len);
            if (isSubsequence(sub, s)) {
                maxLength = max(maxLength, len);
            }
        }
    }

    return maxLength;
}

void solve() {
    string s, k;
    cin >> s >> k;
    int maxLength = longestSubsequenceAsSubstring(s, k);
    int ans = s.size() + k.size() - maxLength;
    cout << ans << endl;
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
