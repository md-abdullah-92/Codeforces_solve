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

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), odd, even;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2) 
            odd.push_back(v[i]);
        else 
            even.push_back(v[i]);
    }

    if (odd.empty() || even.empty()) {
        cout <<0 << endl;
        return;
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    int mx = odd.back(); // Largest odd number
    int x = 0;
    int y=0;
    for (int i = 0; i < even.size(); i++) {
        if (mx < even[i]) {
            x+=2;
            mx = 2 * even[i] + mx;
        } else {
            mx = even[i] + mx;
            x++;
        }
    }
    mx=odd.back();
    reverse(even.begin(), even.end());
     for (int i = 0; i < even.size(); i++) {
        if (mx < even[i]) {
            y+=2;
            mx = 2 * even[i] + mx;
        } else {
            mx = even[i] + mx;
            y++;
        }
    }

    cout << min(x,y)<< endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
