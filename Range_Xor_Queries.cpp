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
    int n,t;
    cin >>n>>t;
    vector<int> v(n+1,0);
    map<int, int> mp;
    cin>>v[1];
    for (int i = 2; i <= n; i++) {
        cin >> v[i];
        v[i]=v[i-1]^v[i];
    }
    while(t--){
        int a,b;
        cin>>a>>b;
        int ans=v[a-1]^v[b];
        cout<<ans<<endl;
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