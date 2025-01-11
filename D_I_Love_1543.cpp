#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to extract a single layer of the carpet in a clockwise order
string extractLayer(vector<string>& grid, int top, int left, int bottom, int right) {
    string layer;

    // Top row (left to right)
    for (int j = left; j <= right; ++j) {
        layer += grid[top][j];
    }

    // Right column (top to bottom)
    for (int i = top + 1; i <= bottom; ++i) {
        layer += grid[i][right];
    }

    // Bottom row (right to left)
    for (int j = right - 1; j >= left; --j) {
        layer += grid[bottom][j];
    }

    // Left column (bottom to top)
    for (int i = bottom - 1; i > top; --i) {
        layer += grid[i][left];
    }
    //cout<<layer<<endl;

    return layer;
}

// Function to count occurrences of "1543" in a string
int countOccurrences(const string& s) {
    int count = 0;
    string p=s+s;
    for (size_t i = 0; i + 3 < p.size(); ++i) {
        if (p.substr(i, 4) == "1543") {
            ++count;
        }
    }
    
    return count/2+count%2;
}

void solve() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m; // Dimensions of the grid
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int totalCount = 0;

        int top = 0, left = 0, bottom = n - 1, right = m - 1;

        // Traverse all layers of the grid
        while (top <= bottom && left <= right) {
            string layer = extractLayer(grid, top, left, bottom, right);
            totalCount += countOccurrences(layer);

            // Move to the next inner layer
            ++top;
            ++left;
            --bottom;
            --right;
        }

        cout << totalCount << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
