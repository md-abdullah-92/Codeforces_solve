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
    int mx=-1;
    int mn=1e10;
    map<int, int> mp;
    int sum=0;
    for (int i = 0; i < n; i++) {
        int k,s;
        cin>>k>>s;
        if(k==1) mx=max(mx,s);
        if(k==3) mn=max(mn,s);
        if(k==2) mp[s]++;
    }
    for(int i=mx;i<=mn;i++) if(!mp[i]) sum++;
    cout<<sum<<endl;
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