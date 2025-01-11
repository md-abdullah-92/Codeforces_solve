#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

// Helper function to calculate the valid range using binary search
int countInRange(int power, int l1, int r1, int l2, int r2) {
    int low = l1, high = r1, left = -1, right = -1;

    // Binary search for the first `i` such that l2 <= power * i
    while (low <= high) {
        int mid = (low + high) / 2;
        if (power * mid >= l2) {
            left = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Binary search for the last `i` such that power * i <= r2
    low = l1, high = r1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (power * mid <= r2) {
            right = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Return the count of valid `i` values
    if (left == -1 || right == -1 || left > right) return 0;
    return right - left + 1;
}

void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    int count = 0;
    int power = 1; // Start with k^0 = 1

    // Loop through powers of k until power > r2
    while (power <= r2) {
        count += countInRange(power, l1, r1, l2, r2);

        // Prevent overflow for power *= k
        if (power > r2 / k) break;
        power *= k;
    }

    cout << count << endl;
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
