#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n;
    string s;
    cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for(i = 0; i < n; i++){
        cin>>v[i];
        mp[v[i]] =i;
    }
    int ans=0;zz
    for(int i=2;i<=n;i++) {
        if(mp[i]<mp[i-1]) ans++;
    }
    cout<<ans<<endl;
    return;
}
     
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}