#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int originalN = n;
    vector<int> ternaryDigits;
    
    // Convert the input number to base-3 (ternary) representation
    while (n) {
        ternaryDigits.push_back(n % 3);
        n /= 3;
    }

    int firstTwoPosition = -1;
    
    // Find the rightmost occurrence of 2 in the ternary representation
    for (int i = 0; i < ternaryDigits.size(); i++) {
        if (ternaryDigits[i] == 2) {
            firstTwoPosition = i;
        }
    }
    
    // If there is no '2' in the ternary representation, output the original number
    if (firstTwoPosition == -1) {
        cout << originalN << endl;
        return;
    }

    // Modify the ternary representation to eliminate the rightmost '2' and set all '0's after it to '1'
    for (int i = 0; i < ternaryDigits.size(); i++) {
        if (i > firstTwoPosition && ternaryDigits[i] == 0) {
            ternaryDigits[i] = 1;
            firstTwoPosition=-1;
            break;
        } else {
            ternaryDigits[i] = 0;
        }
    }
    
    // Append '1' to the end of the modified ternary representation
     if (firstTwoPosition != -1)
    ternaryDigits.push_back(1);
    
    int result = 0, base = 1;

    // Convert the modified ternary representation back to decimal
    for (int i = 0; i < ternaryDigits.size(); i++) {
        result += ternaryDigits[i] * base;
        base *= 3;
    }

    cout << result << endl;
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
