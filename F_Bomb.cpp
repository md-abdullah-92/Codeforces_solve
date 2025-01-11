#include <bits/stdc++.h>
using namespace std;

#define int long long

// Function to calculate the maximum achievable sum for a given 'mid'
bool isValidMid(int n, int k, int mid, const vector<int>& a, const vector<int>& b) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= mid) {
            sum += (a[i] - mid) / b[i] + 1;
        }
        if (sum >= k) return true; // Early exit if we already meet or exceed the requirement
    }
    return sum >= k;
}

// Function to calculate the maximum possible value for the given 'mid'
int calculateMaxValue(int n, int k, int mid, const vector<int>& a, const vector<int>& b) {
    int totalSum = 0;
    int selectedCount = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] >= mid) {
            int m = (a[i] - mid) / b[i] + 1;
            totalSum += 1LL * m * a[i] - 1LL * m * (m - 1) / 2 * b[i];
            selectedCount += m;
        }
    }

    // Adjust the excess items to exactly match 'k'
    totalSum -= 1LL * mid * (selectedCount - k);
    return totalSum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);

    // Input values
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    // Binary search to find the maximum valid 'mid'
    int low = 0, high = 1e9 + 1, mid;
    while (low < high) {
        mid = (low + high + 1) / 2;
        if (isValidMid(n, k, mid, a, b)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    // Calculate the maximum possible value for the determined 'mid'
    int result = calculateMaxValue(n, k, low, a, b);

    cout << result << "\n";
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
