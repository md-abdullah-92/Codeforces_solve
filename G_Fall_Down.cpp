#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int col = 0; col < m; ++col) {
        int drop_position = n - 1;
        for (int row = n - 1; row >= 0; --row) {
            if (grid[row][col] == 'o') {
                drop_position = row - 1;
            } else if (grid[row][col] == '*') {
                grid[row][col] = '.';
                grid[drop_position][col] = '*';
                --drop_position;
            }
        }
    }

    for (const auto& row : grid) {
        cout << row << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
