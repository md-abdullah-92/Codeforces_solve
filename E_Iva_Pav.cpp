#include <iostream>
#include <vector>
#include <algorithm>
const int N = 2e5 + 10;

using namespace std;

int t[4 * N]; 

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = (t[v * 2] & t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return INT_MAX;

    if (l == tl && r == tr) {
        return t[v];
    }

    int tm = (tl + tr) / 2;
    int left_result = query(v * 2, tl, tm, l, min(r, tm));
    int right_result = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return (left_result & right_result);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        build(a, 1, 0, n - 1);

        int q;
        cin >> q;

        while (q--) {
            int l, k;
            cin >> l >> k;
            l--;

            int lo = l, hi = n - 1, ans = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (query(1, 0, n - 1, l, mid) >= k) {
                    ans = mid+1;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cout << ans << " ";
        }

        cout << "\n";
    }

    return 0;
}
