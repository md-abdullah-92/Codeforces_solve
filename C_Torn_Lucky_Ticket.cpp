#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<string> v(n);
    vector<int> ans(n);
    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        int sum = 0;

        // Calculate the sum of digits in the string and create a pair for the map
        for (char c : v[i]) {
            sum += c - '0';
        }

        pair<int, int> p = {sum, v[i].size()};
        mp[p]++;
        ans[i] = sum;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        string s = v[i];
        int sum = ans[i];
        int k = 0;

        for (int j = 0; j < s.size(); j++) {
            k += s[j] - '0';

            // Calculate the pair for the map lookup
            int nk = s.size() - 2 * (j + 1);
            pair<int, int> p = {abs(sum - 2 * k), abs(nk)};

            // Increment the count based on map entries
            count += mp[p];
        }
    }

    cout << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
