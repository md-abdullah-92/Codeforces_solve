#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort candidates by the number of their fans and keep track of their original indices
    vector<pair<int, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());

    // Prefix sums to quickly calculate undecided votes if we exclude certain candidates
    vector<int> prefix_sum(n);
    prefix_sum[0] = candidates[0].first;
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + candidates[i].first;
    }

    vector<int> result(n, LLONG_MAX);

    // Calculate minimum exclusions for each candidate
    for (int i = 0; i < n; ++i) {
        int current_candidate_votes = candidates[i].first;
        int undecided_votes = c;

        // Calculate the votes required for the current candidate to win
        int required_votes = current_candidate_votes + undecided_votes;

        // Binary search to find the point where current candidate can be made the winner
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (candidates[mid].first < required_votes) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Number of candidates to exclude
        int excludes_needed = n - left;

        // Handle the case where we are at the candidate itself
        for (int j = i; j >= 0; --j) {
            int remaining_undecided_votes = c + (j > 0 ? prefix_sum[j - 1] : 0);
            if (remaining_undecided_votes >= required_votes) {
                excludes_needed = min(excludes_needed, i - j);
            }
        }

        result[candidates[i].second] = excludes_needed;
    }

    // Print results
    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';
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
