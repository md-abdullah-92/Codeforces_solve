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
    vector<int> v(n);

    for (int i = 0; i < n; i++) { 
        cin >> v[i];
        cout<<v[i];
        if(i!=n-1) cout<<" ";
    }
        cout<<endl;

    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;

        // Shift elements of v[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;

        // Print the array after each insertion step
        for (int k = 0; k < n; k++) { 
            cout << v[k];
             if(k!=n-1) cout<<" ";
        }
        cout << endl;
    }

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
 //   cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
