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

void solve(int count, vector<int>& values) {
    map<int, int> mp;
    int odd_count = 0, even_count = 0;
    for (int i = 0; i < count; i++) {
        if(values[i] % 2) odd_count++;
        else even_count++;
    }
    if(odd_count == count) {
        cout << count - 1 << endl;
    } else {
        int result = odd_count + 1;
        cout << result << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        int count;
        cin >> count;
        vector<int> values(count);
        for (int i = 0; i < count; i++) {
            cin >> values[i];
        }
        solve(count, values);
    }
    return 0;
}
