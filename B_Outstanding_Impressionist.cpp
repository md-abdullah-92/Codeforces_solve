#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n); // Input vector
    vector<int> a(2 * n + 2, 0); // Map for storing counts of values
    map<int, int> mp1; // Map for diagonal elements (when first == second)

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first == v[i].second) {
            mp1[v[i].first]++;
            a[v[i].first] = 1;
        }
    }

    // Process the cumulative frequency array
    for (int i = 1; i <= 2 * n; i++) {
        a[i] += a[i - 1]; // Cumulative sum to manage intervals
    }

    // Output based on the counts
    for (int i = 0; i < n; i++) {
        int l = v[i].first, r = v[i].second;
        if (l == r) {
          if(mp1[l]>1)
            cout << "0";
            else{
                cout << "1";
            }

        }else if (a[r] - a[l - 1] == (r - l + 1)) {
            cout << "0";
        } else {
            cout << "1";
        }
    }
    cout << endl;
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
