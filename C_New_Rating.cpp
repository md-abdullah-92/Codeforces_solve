#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int a, int x) {
    return a + (a < x) - (a > x);
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n; // Size of the array
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> dp(3, 0);
        dp[0] = 0;
        dp[1] = -n;
        dp[2] = -n;

        for (int x : arr) {
            dp[2] = max(f(dp[1], x), f(dp[2], x));
            dp[1] = max(dp[1], dp[0]);
            dp[0] = f(dp[0], x);
          //  cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<endl;
        }

        cout << max(dp[1], dp[2]) << endl;
    }

    return 0;
}
