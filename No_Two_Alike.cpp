#include <bits/stdc++.h>
using namespace std;

int minCostDistinct(int n, vector<int>& arr) {
    // Step 1: Track the first and last occurrence of each element
    unordered_map<int, pair<int, int>> occ;
    for (int i = 0; i < n; ++i) {
        if (occ.find(arr[i]) == occ.end()) {
            occ[arr[i]] = {i, i}; // First occurrence
        } else {
            occ[arr[i]].second = i; // Update last occurrence
        }
    }

    // Step 2: Form intervals for duplicate elements
    vector<pair<int, int>> intervals;
    for (const auto& [val, range] : occ) {
        if (range.first != range.second) { // Only consider duplicates
            intervals.push_back(range);
        }
    }

    if (intervals.empty()) {
        return 0; // No duplicates, no cost
    }

    // Step 3: Merge overlapping intervals
    sort(intervals.begin(), intervals.end()); // Sort by start of intervals
    vector<pair<int, int>> merged;

    int start = intervals[0].first;
    int end = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first <= end) { // Overlapping
            end = max(end, intervals[i].second);
        } else {
            merged.push_back({start, end});
            start = intervals[i].first;
            end = intervals[i].second;
        }
    }
    merged.push_back({start, end});

    // Step 4: Calculate the cost
    int cost = 0;
    for (const auto& interval : merged) {
        set<int> distinct(arr.begin() + interval.first, arr.begin() + interval.second + 1);
        cost += distinct.size();
    }

    return cost;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << minCostDistinct(n, arr) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
