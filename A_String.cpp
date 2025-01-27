#include <bits/stdc++.h>

using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
void solve()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]-'0') cnt++;
    }
    cout << cnt << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
