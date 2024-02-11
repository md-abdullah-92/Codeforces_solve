#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m;
    cin >>n>>m;
    vector<int> v(n),ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i=1;i<n;i++){
        ans.push_back(v[i]-v[i-1]);
    }
    sort(ans.begin(),ans.end());
    m-=1;
    int ans1=0;
    for(int i=0;i<ans.size()-m;i++) ans1+=ans[i];
    cout<<ans1<<endl;
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