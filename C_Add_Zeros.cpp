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
    vector<int> v(n),ans(n);
    vector<pair<int,int>> vp;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ans[i]=v[i]+i;
        
        vp.push_back({ans[i],i});
    }
    sort(vp.begin(),vp.end());
    mp[n]=1;
    int sum=0;
    for(int i=0;i<n;i++) {
      //  cout<<vp[i].first<<" "<<vp[i].second<<endl;
        if(mp[vp[i].first]) {
            mp[vp[i].first+vp[i].second]=1;
            sum=vp[i].first+vp[i].second;
        
        }
    }
    
   

    cout << sum << "\n";
    

    
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