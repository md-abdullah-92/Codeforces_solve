#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int findKthDigit(long long k) {
    long long digits = 1;       // Length of numbers in the current range
    long long start = 1;        // Starting number of the current range
    long long count = 9;        // Number of integers in the current range

    // Determine the range where k lies
    while (k > digits * count) {
        k -= digits * count;    // Reduce k by the total digits in the current range
        digits++;               // Move to the next range of numbers
        start *= 10;            // Update the starting number of the range
        count *= 10;            // Update the count of numbers in the range
    }

    // Find the exact number
    long long num = start + (k - 1) / digits;
    // Find the specific digit in the number
    int digitIndex = (k - 1) % digits;

    // Convert the number to string to extract the specific digit
    string numStr = to_string(num);
    return numStr[digitIndex] - '0';
}

void solve()
{
    int n;
    cin >> n;
    int x=findKthDigit(n);
    cout<<x<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}