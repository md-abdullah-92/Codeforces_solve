#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // number of test cases

    while (t--) {
        int n;
        cin >> n;  // size of the matrix
        vector<vector<int>> matrix(n, vector<int>(n));

        // Input the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        int operations = 0;

        // Traverse diagonals starting from each position (i, i)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int min_element = 0;  // Track the minimum element in the diagonal
                
                // Traverse along the diagonal starting at (i, j)
                for (int x = i - j, y = j; x < n && y < n; x++, y++) {
                    if (matrix[x][y] < 0) {
                        min_element = min(min_element, matrix[x][y]);
                    }
                }

                // If the minimum element is negative, we need |min_element| operations
                if (min_element < 0) {
                    int add_value = -min_element;
                    operations += add_value;

                    // Apply the operations to the diagonal
                    for (int x = i - j, y = j; x < n && y < n; x++, y++) {
                        matrix[x][y] += add_value;
                    }
                }
            }
        }

        // Output the result for this test case
        cout << operations << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);  // Faster input/output
    
    solve();

    return 0;
}
