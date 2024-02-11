#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200005], tree[4 * 200005];

void build(int node, int st, int en) {
    if (st == en) {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int l, int r) {
    if (l > en || st > r) {
        return 0;
    }
    if (l <= st && en <= r) {
        return tree[node];
    }
    int mid = (st + en) / 2;
    int left = query(2 * node, st, mid, l, r);
    int right = query(2 * node + 1, mid + 1, en, l, r);
    return left + right;
}

void update(int node, int st, int en, int idx, int val) {
    if (st == en) {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;
    if (idx <= mid) {
        update(2 * node, st, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, en, idx, val);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int32_t main() {
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(1, 0, n - 1);
        cout << "Case " << tc++ << ": " << endl;
        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int x;
                cin >> x;
                cout << a[x] << endl;
                update(1, 0, n - 1, x, 0);
                a[x] = 0;
            } else if (type == 2) {
                int idx, val;
                cin >> idx >> val;
                a[idx] += val;
                update(1, 0, n - 1, idx, a[idx]);
            } else {
                int l, r;
                cin >> l >> r;
                cout << query(1, 0, n - 1, l, r) << '\n';
            }
        }
    }
}
