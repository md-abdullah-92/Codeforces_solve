#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v(n),mp(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    yes;
    set<pair<int,int>>st;
    for(int i=1;i<=m;i++){
        st.insert({0,i});
    }
    for(int i=0;i<n;i++){
        auto p=st.begin();
        int x=p->first;
        int y=p->second;
        mp[i]=y;
        st.erase(*st.begin());
        st.insert({(x+v[i]),y});
    }
    for(int i=0;i<n;i++) cout<<mp[i]<<" ";
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
