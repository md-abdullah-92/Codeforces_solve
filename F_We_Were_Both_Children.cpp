#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> values(n + 1); // Input values
    vector<int> freq(n + 1, 0); // Frequency of each number (1 to n)
    set<int> uniqueValues; // Set of unique valid values

    // Reading input and filtering valid values
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
        if (values[i] <= n) {
            uniqueValues.insert(values[i]);
            freq[values[i]]++;
        }
    }

    vector<int> divisorFreq(n + 1, 0);

    // Updating divisor frequencies
    for (int x : uniqueValues) {
        for (int j = x; j <= n; j += x) {
            divisorFreq[j] += freq[x]; // Increment by the frequency of value x
        }
    }

    // Finding the maximum frequency
    int maxFreq = 0;
    for (int i = 1; i <= n; i++) {
        maxFreq = max(maxFreq, divisorFreq[i]);
    }

    cout << maxFreq << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
