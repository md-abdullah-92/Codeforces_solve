#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    // Check for two consecutive identical characters
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << s[i] << s[i + 1] << endl;
            return;
        }
    }
    
    // Check for unique patterns of length 3
    for (int i = 0; i < n - 2; i++) {
        if (s[i] != s[i + 1] && s[i] != s[i + 2]) {
            cout << s[i] << s[i + 1] << s[i + 2] << endl;
            return;
        }
    }
    
    // Check for unique patterns of length 4
    for (int i = 0; i < n - 3; i++) {
        if (s[i] != s[i + 2] || s[i + 1] != s[i + 3]) {
            cout << s[i] << s[i + 1] << s[i + 2] << s[i + 3] << endl;
            return;
        }
    }
    
    // If no such patterns are found
    cout << -1 << endl;
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
