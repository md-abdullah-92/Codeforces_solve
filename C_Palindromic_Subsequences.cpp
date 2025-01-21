#include <bits/stdc++.h>

using namespace std;

#define int long long

// Function to solve a single test case
void solveTestCase() 
{
    int arraySize;
    cin >> arraySize;

    vector<int> sequence(arraySize);
    map<int, int> frequencyMap;

    // Output sequence according to the problem statement
    cout << "1 1" << " ";
    for (int index = 2; index < arraySize - 1; ++index) {
        cout << index << " ";
    }
    cout << 1 << endl;

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
