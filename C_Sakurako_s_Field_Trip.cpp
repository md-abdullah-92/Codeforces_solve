#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    vector<vector<int>> dp((n + 1) / 2, vector<int>(2, LLONG_MAX));
    dp[0][0] = dp[0][1] = 0;

    int sz = (n + 1) / 2;
    for(int i = 1; i < sz; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + (v[i] == v[i - 1]) + (v[n - i] == v[n - i - 1]),
                       dp[i - 1][1] + (v[i] == v[n - i]) + (v[i - 1] == v[n - i - 1]));
        dp[i][1] = min(dp[i - 1][0] + (v[i] == v[n - i]) + (v[i - 1] == v[n - i - 1]),
                       dp[i - 1][1] + (v[i] == v[i - 1]) + (v[n - i] == v[n - i - 1]));
    }
    
    int ans = min(dp[sz - 1][0], dp[sz - 1][1]);
    if (n % 2 == 0)
        ans += (v[n / 2 - 1] == v[n / 2]);
    
    cout << ans << '\n';
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
