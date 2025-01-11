#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Aliases for easier usage
#define int long long

// Custom ordered set using PBDS
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Function to solve the problem
void solve()
{
    int l = 1, r = 999; // Define the range of the search
    while (r - l > 2) { // Continue narrowing down until the range has 2 or fewer elements
        int mid1 = l + (r - l) / 3; // First division point in ternary search
        int mid2 = r - (r - l) / 3; // Second division point in ternary search

        // Ask a question for the range mid1 to mid2
        cout << "? " << mid1 << " " << mid2 << endl;
        int rs; // Response from the query
        cin >> rs;

        // Adjust the range based on the response
        if (rs == (mid1 + 1) * (mid2 + 1)) {
            r = mid1; // Narrow the range to the left
        } else if (rs == (mid1) * (mid2)) {
            l = mid2; // Narrow the range to the right
        } else {
            l = mid1;
            r = mid2; // Narrow the range to the middle segment
        }
    }

    // Final adjustment when the range has exactly 3 elements
    if (r - l == 2) {
        // Query the middle element directly
        cout << "? 1 " << l + 1 << endl;
        int resp;
        cin >> resp;

        // Determine the final answer based on the response
        if (resp == l + 1) {
            r = l + 1;
        } else {
            r = l + 1;
        }
    }

    // Output the result
    cout << "! " << r << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); // Speed up I/O
    cin.tie(nullptr);

    int T;
    cin >> T; // Number of test cases
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}
