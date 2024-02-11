#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    map<int, int> mp;
    int even_count = 0, div_4_count = 0;
    
    // Input and count even and divisible by 4 numbers
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) even_count++;
        if (v[i] % 4 == 0) div_4_count++;
    }
    
    int min_operations = m; // Initialize min_operations to 'm'

    // Find the minimum number of operations needed
    for (int i = 0; i < n; i++) {
        if (v[i] % m) {
            min_operations = min(min_operations, (m - v[i] % m));
        } else {
            min_operations = 0; // No need to continue, we found a number divisible by 'm'
            break;
        }
    }
    
    if (m == 4) {
        // Special case for m=4
        if (even_count >= 2 || div_4_count) {
            cout << 0 << endl;
        } else {
            cout << min(2 - even_count, min_operations) << endl;
        }
    } else {
        cout << min_operations << endl;
    }
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
