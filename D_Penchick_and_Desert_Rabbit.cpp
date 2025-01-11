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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int>mx(n),mn(n),ans(n);
    mx[0]=v[0];
    mn[n-1]=v[n-1];
    for(int i=1;i<n;i++) mx[i]=max(mx[i-1],v[i]);
    for(int i=n-2;i>=0;i--) mn[i]=min(mn[i+1],v[i]);

    
    ans[n-1]=mx[n-1];
    for(int i=n-2;i>=0;i--){
        if(mx[i]>mn[i+1]) ans[i]=ans[i+1];
        else ans[i]=mx[i];
        
    }
    for(int x:ans) cout<<x<<" ";
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