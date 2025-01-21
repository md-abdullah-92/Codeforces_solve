#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

// Comparator function for sorting intervals
bool cmp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if (a.first.first != b.first.first)
        return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> intervals;

    // Reading the intervals and their indices
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        intervals.push_back({{x, y}, i + 1}); // Store interval and its index
    }

    // Sort intervals using the custom comparator
    sort(intervals.begin(), intervals.end(), cmp);

    int l = -1, r = -1; // Initialize the range variables

    // Process each interval
    for (int i = 0; i < n; i++) {
        int x = intervals[i].first.first;  // Start of current interval
        int y = intervals[i].first.second; // End of current interval
        int id = intervals[i].second;   // Index of the current interval

        // Check if the current interval is fully covered by the previous range
        if (l <= x && y <= r) {
            cout << id << "\n"; // Found the interval
            return;
        }

        // If the current interval overlaps with the range
        if (x <= r) {
            // Check the next interval for potential extension
            if (i + 1 < n) {
                int tx = intervals[i + 1].first.first; // Start of the next interval
                int ty = intervals[i + 1].first.second; // End of the next interval

                // If the next interval extends the range to cover the current one
                if (tx <= r + 1 && ty >= y) {
                    cout << id << "\n"; // Found the interval
                    return;
                }
            }

            // Update the range to include the current interval
            r = max(r, y);
        } else {
            // If no overlap, reset the range to the current interval
            l = x;
            r = y;
        }
    }

    // If no such interval is found
    cout << -1 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // Uncomment if multiple test cases are required
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
} 