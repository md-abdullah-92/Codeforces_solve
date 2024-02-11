#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> mp;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        s2 += ";";
        mp[s2] = s1;
        v[i] = s1;
    }

    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << s1 << " " << s2 << " #" << mp[s2] << endl;
    }
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
