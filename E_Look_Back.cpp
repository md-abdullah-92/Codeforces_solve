#include <iostream>
#include <vector>
#define int unsigned long long
using namespace std;

int minOperationsToMakeNonDecreasing(int n, vector<int>& arr) {
    int operations = 0;
    int prev = arr[0];

    for (int i = 1; i < n; ++i) {
        while (arr[i] < prev) {
            arr[i] *= 2;
            operations++;
        }
        prev = arr[i];
    }

    return operations;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int operations = minOperationsToMakeNonDecreasing(n, arr);
        cout << operations << endl;
    }

    return 0;
}
