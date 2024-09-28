#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void applyOperation(vector<vector<int>>& a, int x, int y) {
    a[x][y] = (a[x][y] + 1) % 3;
    a[x][y + 1] = (a[x][y + 1] + 2) % 3;
    a[x + 1][y] = (a[x + 1][y] + 2) % 3;
    a[x + 1][y + 1] = (a[x + 1][y + 1] + 1) % 3;
}

bool canConvertGrids(int n, int m, vector<vector<int>>& a, const vector<vector<int>>& b) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            while (a[i][j] != b[i][j]) {
                applyOperation(a, i, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i][m - 1] != b[i][m - 1]) return false;
    }
    for (int j = 0; j < m; ++j) {
        if (a[n - 1][j] != b[n - 1][j]) return false;
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            a[i][j] = row[j] - '0';
        }
    }
    
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            b[i][j] = row[j] - '0';
        }
    }
    
    if (canConvertGrids(n, m, a, b)) {
        yes
    } else {
        no
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
