#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long 

vector<int> prefix_sum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    return prefix;
}

bool find_valid_subarray(const vector<int>& prefix, int target, int start, int end, int &l, int &r) {
    for (int i = start; i <= end; ++i) {
        auto it = lower_bound(prefix.begin() + i + 1, prefix.begin() + end + 2, prefix[i] + target);
        if (it != prefix.begin() + end + 2) {
            l = i;
            r = it - prefix.begin() - 1;
            return true;
        }
    }
    return false;
}

bool solve_case(int n, const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    int tot = accumulate(a.begin(), a.end(), 0ULL);
    int target = (tot + 2) / 3;

    vector<int> prefixA = prefix_sum(a);
    vector<int> prefixB = prefix_sum(b);
    vector<int> prefixC = prefix_sum(c);

    int la, ra, lb, rb, lc, rc;

    if (find_valid_subarray(prefixA, target, 0, n - 1, la, ra) &&
        find_valid_subarray(prefixB, target, ra + 1, n - 1, lb, rb) &&
        find_valid_subarray(prefixC, target, rb + 1, n - 1, lc, rc)) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
        return true;
    }

    if (find_valid_subarray(prefixB, target, 0, n - 1, lb, rb) &&
        find_valid_subarray(prefixC, target, rb + 1, n - 1, lc, rc) &&
        find_valid_subarray(prefixA, target, rc + 1, n - 1, la, ra)) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
        return true;
    }

    if (find_valid_subarray(prefixC, target, 0, n - 1, lc, rc) &&
        find_valid_subarray(prefixA, target, rc + 1, n - 1, la, ra) &&
        find_valid_subarray(prefixB, target, ra + 1, n - 1, lb, rb)) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
        return true;
    }

    if (find_valid_subarray(prefixB, target, 0, n - 1, lb, rb) &&
        find_valid_subarray(prefixA, target, rb + 1, n - 1, la, ra) &&
        find_valid_subarray(prefixC, target, ra + 1, n - 1, lc, rc)) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
        return true;
    }

    if (find_valid_subarray(prefixC, target, 0, n - 1, lc, rc) &&
        find_valid_subarray(prefixB, target, rc + 1, n - 1, lb, rb) &&
        find_valid_subarray(prefixA, target, rb + 1, n - 1, la, ra)) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
        return true;
    }

    if (find_valid_subarray(prefixA, target, 0, n - 1, la, ra) &&
        find_valid_subarray(prefixC, target, ra + 1, n - 1, lc, rc) &&
        find_valid_subarray(prefixB, target, rc + 1, n - 1, lb, rb)) {
        cout << la + 1 << " " << ra + 1 << " " << lb + 1 << " " << rb + 1 << " " << lc + 1 << " " << rc + 1 << '\n';
        return true;
    }

    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];

        if (!solve_case(n, a, b, c)) {
            cout << -1 << '\n';
        }
    }

    return 0;
}
