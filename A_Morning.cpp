#include <iostream>
#include <string>
using namespace std;

#define int long long

void solve() {
    int n;
    string s;
    cin >> s;
    int ans = 4;
    string p = "1";
    p += s;

    for (int i = 0; i < 4; i++) {
        int digit1 = p[i] - '0';
        int digit2 = p[i + 1] - '0';

        if (digit1 == 0 && digit2 != 0) {
            ans += (10 - digit2);
        } else if (digit2 == 0 && digit1 != 0) {
            ans += (10 - digit1);
        } else {
            ans += abs(digit1 - digit2);
        }
    }

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
