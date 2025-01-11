#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

int k; // Target value for binary search
unordered_map<int, int> frequency_map;

// Helper function to check if a given value `mid` satisfies the condition
bool isValid(const vector<int>& values, int mid) {
    int count = 0;
    for (int x : values) {
        if (x > mid) continue; // Skip elements that are larger than `mid`
        count += (mid / x);
        if (count >= k) return true; // Early exit if condition is met
    }
    return false;
}

void solve() {
    int n;
    cin >> n >> k;

    vector<int> values;

    // Read the input and track frequencies of each element
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
      //  if (frequency_map[x] == 0) {
            values.push_back(x);
       // }
       // frequency_map[x]++;
    }

    // Sort values for better performance in the `isValid` function
    sort(values.begin(), values.end());

    // Binary search for the minimum value satisfying the condition
    int low = 1, high = 1e18, result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValid(values, mid)) {
            result = mid;
            high = mid - 1; // Try to find a smaller valid value
        } else {
            low = mid + 1; // Increase the range to find a valid value
        }
    }

    cout << result << endl; // Output the result
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases; // Uncomment for multiple test cases
    while (test_cases--) {
        solve();
    }

    return 0;
}
