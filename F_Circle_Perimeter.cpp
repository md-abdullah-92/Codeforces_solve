#include <bits/stdc++.h>
using namespace std;

#define int long long
int r;
int count_valid_y(int x, int r2, int r1_2) {
    int count = 0;

    // Finding the minimum y using binary search
    int lo = 0, hi = r + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (x * x + mid * mid >= r2) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int min_y = lo;

    // Finding the maximum y using binary search
    lo = 0, hi = r + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (x * x + mid * mid < r1_2) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    int max_y = lo - 1;

    if (min_y <= max_y) {
        count = max_y - min_y + 1;
    }

    return count;
}

void solve() {
   // int r;
    cin >> r;
    int r2 = r * r;
    int r1_2 = (r + 1) * (r + 1);
    int count = 0;

    for (int x = 0; x <= r + 1; ++x) {
        int valid_y_count = count_valid_y(x, r2, r1_2);
        if (x == 0) {
            // If x is 0, count only the points along y axis
            count += valid_y_count;
        } else {
            // Else, multiply by 4 to account for all quadrants
            count += 4 * valid_y_count;
        }
    }

    cout << count -1<< '\n';
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
