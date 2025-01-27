#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int array_size;
    cin >> array_size;
    vector<int> values(array_size);
    map<int, int> frequency_map;
    for (int index = 0; index < array_size; index++) {
        cin >> values[index];
    }
    for (int index = 0; index < array_size; index++) {
       int threshold = max(2 * (array_size - index - 1), 2 * index);
       if (values[index] <= threshold) {
           no;
           return;
       }
    }
    yes;
    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}
