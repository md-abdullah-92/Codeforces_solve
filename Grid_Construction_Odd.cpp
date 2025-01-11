#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int v[500][500];

void solve() {
    cin >> n;
    deque<int> d, q;

    // Initialize deque `d` with values 1 to n/2 and deque `q` with n/2 + 1 to n
    for (int i = 1; i <= n / 2; i++) d.push_back(i);
    for (int i = n / 2 + 1; i <= n; i++) q.push_back(i);

    // Fill the top-left and bottom-right quadrants with cyclic permutations
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            v[i][j] = d[j];
            v[n - i - 1][n - j - 1] = d[j];
        }
        // Rotate deque `d` to create the cyclic pattern
        int x = d.back();
        d.pop_back();
        d.push_front(x);
    }

    // Fill the top-right and bottom-left quadrants with cyclic permutations
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            v[i][n / 2 + j] = q[j];
            v[n - i - 1][n / 2 - j - 1] = q[j];
        }
        // Rotate deque `q` to create the cyclic pattern
        int x = q.front();
        q.pop_front();
        q.push_back(x);
    }

    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
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
