#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin>>n>>m;
    map<int, int> mp;
    for (int i = 0; i <m; i++) {
        cout<<i+1<<" ";
    }
    for(int i=n;i>(m);i--)  cout<<i<<" ";
    cout<<endl;
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