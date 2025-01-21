#include <bits/stdc++.h>
using namespace std;

#define int long long


// Function to solve a single test case
void solveTestCase()
{
    int rows, columns;
    cin >> rows >> columns;

    vector<int> values(rows); // Placeholder vector (not used in calculations)

    int totalCost = 0;
    int firstRow, firstCol;
    cin >> firstRow >> firstCol;

    // Initializing total cost as the entire grid's boundary perimeter
    totalCost += rows * columns * 4;

    map<int, int> adjustments; // Placeholder map (not used in calculations)

    for (int rowIndex = 1; rowIndex < rows; rowIndex++) {
        int x, y;
        cin >> x >> y;

        // Subtract the perimeter adjustment for the current position
        totalCost -= 2 * (2*columns - x  - y);
    }

    cout << totalCost << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solveTestCase();
    }

    return 0;
}
