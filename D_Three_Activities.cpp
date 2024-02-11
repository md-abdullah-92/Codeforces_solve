#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v1(n),v2(n),v3(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v1[i].first;
        v1[i].second=i;
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i].first;
         v2[i].second=i;
    }
    for (int i = 0; i < n; i++) {
        cin >> v3[i].first;
         v3[i].second=i;
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    reverse(v3.begin(),v3.end());
    
    int ans=0;
    for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
         for(int k=0;k<3;k++)
           if(v1[i].second !=v2[j].second && v1[i].second != v3[k].second && v2[j].second != v3[k].second )
              ans=max(ans,(v1[i].first+v2[j].first+v3[k].first));
    



    cout<<ans<<endl;    
    
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