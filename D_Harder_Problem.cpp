#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp,mp1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(mp[i]==0) ans.push_back(i);
    }
    int j=0;
    for(int i=0;i<n;i++){
     if(mp1[v[i]]==0){
        cout<<v[i]<<" ";
        mp1[v[i]]++;
     }
     else{
        cout<<ans[j]<<" ";
        j++;
     }
    }
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