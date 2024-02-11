#include <bits/stdc++.h>
using namespace std;

#define int     long long 
#define yes     cout<<"YES\n"
#define no      cout<<"NO\n"


void solve()
{
    int i,j,k,n,m;
    string s;
    cin>>n>>m;
    int xr=0,ox=0,ans=0;
    vector<int> v1(n),v2(m);
    map<int, int> mp;
    for(i = 0; i < n; i++){
        cin>>v1[i];
        xr^=v1[i];
    }
    for(i = 0; i < m; i++){
        cin>>v2[i];
        ox|=v2[i];
    }
     for(i = 0; i < n; i++){
        ans^=(ox|v1[i]);
    }
    cout<<min(ans,xr)<<" "<<max(ans,xr)<<endl;
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