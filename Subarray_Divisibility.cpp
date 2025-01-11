#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> prefixSumCount; // To store prefix sums modulo n and their frequencies
    prefixSumCount[0] = 1;        // Initialize for subarrays starting at index 0

    int prefixSum = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += v[i]%n;
        prefixSum  = (prefixSum + n)%n;
      //  cout<<prefixSum <<endl;
        ans += prefixSumCount[prefixSum];     
        prefixSumCount[prefixSum ]++;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T; // Uncomment for multiple test cases
    while (T--) {
        solve();
    }
    return 0;
}
