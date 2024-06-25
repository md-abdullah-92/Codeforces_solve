#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define pii pair<int, int>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    // Read the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> new_matrix = matrix; // Create a copy to store the new values

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<int> neighbors;


            // Right neighbor
            if (j + 1 < m) {
                neighbors.push_back(matrix[i][j + 1]);
            }

            // Down neighbor
            if (i + 1 < n) {
                neighbors.push_back(matrix[i + 1][j]);
            }

            // Up neighbor
            if (i - 1 >= 0) {
                neighbors.push_back(matrix[i - 1][j]);
            }

            // Left neighbor
            if (j - 1 >= 0) {
                neighbors.push_back(matrix[i][j - 1]);
            }

            // Find the minimum value among the neighbors
            int min_value = *min_element(neighbors.begin(), neighbors.end());
            sort(neighbors.begin(), neighbors.end());
            if(matrix[i][j]> neighbors[neighbors.size()-1])
                new_matrix[i][j] = neighbors[neighbors.size()-1];
        }
    }

    // Output the new matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return; 
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
