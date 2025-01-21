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

const int mod=998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, int> right,left;
    right[0] = 1; 
    for (int i = 0; i < n; i++) {
            int x=v[i];
            int count = (right[x] + left[x]) % mod;
            map<int, int> new_right, new_left;
            if (count > 0) {
                new_right[x] = count;
            }
            for (auto& [key, cnt] : right) {
                new_left[key + 1] = (new_left[key + 1] + cnt) % mod;
            }
            right = new_right;
            left =new_left;
        }
        int total_count = 0;
        for (auto& [key, count] : right) {
            total_count = (total_count + count) % mod;
        }
        for (auto& [key, count] : left) {
            total_count = (total_count + count) % mod;
        }
     cout << total_count << "\n";
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