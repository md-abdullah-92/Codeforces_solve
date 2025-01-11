#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define commonly used types and macros
#define int long long
#define printYes cout << "YES\n";
#define printNo cout << "NO\n";

// Order statistic tree (useful for advanced queries)
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Function to solve each test case
void solve() {
    int arraySize, maxSwaps;
    cin >> arraySize >> maxSwaps;

    // Read array A and B along with their indices
    vector<pair<int, int>> arrayA(arraySize), arrayB(arraySize);
    for (int i = 0; i < arraySize; i++) {
        cin >> arrayA[i].first;
        arrayA[i].second = i; // Store the original index
    }
    for (int i = 0; i < arraySize; i++) {
        cin >> arrayB[i].first;
        arrayB[i].second = i; // Store the original index
    }

    // Sort both arrays based on their values
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int swapsNeededFromStart = 0;
    int swapsNeededFromEnd = 0;
    int swapsWithReversed = 0;

    // Count swaps required for different conditions
    for (int i = 0; i < arraySize; i++) {
        if (arrayA[i].first > arrayB[i].first) {
            swapsNeededFromStart++;
        }
    }
    for (int i = 0; i < arraySize; i++) {
        if (arrayA[arraySize - i - 1].first > arrayB[i].first) {
            swapsNeededFromEnd++;
        }
    }
    for (int i = 0; i < arraySize; i++) {
        if (arrayA[i].first > arrayB[arraySize - i - 1].first) {
            swapsWithReversed++;
        }
    }
    cou
    // Check if the conditions are satisfied
    if (min(swapsWithReversed, swapsNeededFromEnd) > maxSwaps || maxSwaps < swapsNeededFromStart) {
        printNo;
        return;
    }

    // Adjust array B by swapping elements
    for (int i = 0; i < (swapsNeededFromStart - maxSwaps); i++) {
        swap(arrayB[i], arrayB[arraySize - i - 1]);
    }

    // Print the results
    printYes;
    for (const auto& element : arrayB) {
        cout << element.first << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
