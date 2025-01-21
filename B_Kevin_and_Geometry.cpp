#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());

    int duplicate1 = -1, duplicate2 = -1; // Initialize with invalid values
    for (int i = 1; i < n; i++) {
        if (values[i] == values[i - 1]) {
            duplicate1 = values[i];
            duplicate2 = values[i - 1];
            values.erase(values.begin() + i);
            values.erase(values.begin() + i - 1);
            break;  // Remove only the first duplicate found
        }
    }

    if (duplicate1 == -1) {
        cout << "-1\n";
        return;
    }

    double half_distance = 0;
    for (int i = 1; i < values.size(); i++) {
        half_distance = (values[i] - values[i - 1]) / 2.00;
        double p = pow(duplicate1, 2) - pow(half_distance, 2);
        if (p > 0) {
            cout << duplicate1 << " " << duplicate2 << " " << values[i - 1] << " " << values[i] << endl;
            return;
        }
    }

    cout << "-1\n";  // If no valid combination is found
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}
