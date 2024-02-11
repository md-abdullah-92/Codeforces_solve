#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,a,b;
    cin >>n>>a>>b;
    vector<int> v(n);
    map<int, int> mp;
    int ans=-1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]==(a+b)) ans=i+1;
    }
    cout<<ans<<endl;
    return;
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