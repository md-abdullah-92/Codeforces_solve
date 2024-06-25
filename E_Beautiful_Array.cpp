#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

bool can_make_beautiful(int n, int k, vector<int>& a, int ops) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int ai = a[left];
        int aj = a[right];
        int d = abs(ai - aj);
        if (d > ops * k) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int min_operations_to_make_beautiful(int n, int k, vector<int>& a) {
    if (k == 0) {
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] != a[n - i - 1]) {
                return -1;
            }
        }
        return 0;
    }

    sort(a.begin(), a.end());

    int low = 0;
    int high = INT_MAX / k; // Set a high enough upper bound for binary search

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (can_make_beautiful(n, k, a, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> results;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int result = min_operations_to_make_beautiful(n, k, a);
        results.push_back(result);
    }

    for (const int& result : results) {
        cout << result << "\n";
    }

    return 0;
}
