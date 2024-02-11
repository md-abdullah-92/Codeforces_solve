#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

bool hasEqualSums(int arr[], int n) {
    int sum = 0;
    unordered_set<int> prefixSums;

    for (int i = 0; i < n; ++i) {
        sum += (i % 2 == 0) ? arr[i] : -arr[i];
        
        if (sum == 0 || prefixSums.count(sum)) {
            return true;
        }

        prefixSums.insert(sum);
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    int v[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (hasEqualSums(v, n)) {
        yes;
    } else {
        no;
    }

    return;
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
