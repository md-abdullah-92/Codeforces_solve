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
    map<int, int> mp;
    int mx=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        mx=max(mx,mp[v[i]]);
    }
    int p=n-mx;
    cout<<max((mx-p),(n%2))<<endl;
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