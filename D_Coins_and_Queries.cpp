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
    int n,q;
    cin >> n>>q;
    vector<int> v;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(mp[x]==0) v.push_back(x);
        mp[x]++;

    }
    sort(v.begin(),v.end(),greater<int>());
    while(q--){
        int x;
        cin >> x;
        int ans=0;
        for(int i=0;i<v.size();i++){

            if(v[i]<=x){
                int k=x/v[i];
               // cout<<k<<" "<<mp[v[i]]<<" "<<'\n';
                x-=min(k,mp[v[i]])*v[i];
                ans+=min(k,mp[v[i]]);
            }
            
        }
        if(x==0) cout<<ans<<'\n';
        else
        cout<<"-1"<<'\n';
    }
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