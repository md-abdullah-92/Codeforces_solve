#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int k = 0;

    // Count leading '1's
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            break;
        }
        k++;
    }
    cout << 1 << " " << n << " ";
    // Handle the case where the entire string is '1'
    if (k == n) {
        cout << n << " " << n << endl;
        return;
    }

    // Find the range with the maximum number of zeros
    int ln = n - k; // Length of the segment to analyze
    int st = 0, ed = 0, mx = 0;
    
    for (int i = 0; i < n - ln; i++) {
        int p = 0;
        int aj=k;

        for (int j = i; j <= i + ln; j++) {
            if (s[j] == s[aj]) {
                break;
            }
         //   cout<<s[j]<<" "<<s[aj]<<" "<<aj<<endl;
            p++;
            aj++;
        }

        if (p > mx) {
            mx = p;
            st = i + 1;
            ed = i + ln;
        }
    }

    cout << st << " " << ed << endl;
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
