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
    vector<int> v(n-1),ans(n);
    map<int, int> mp;
    
    for (int i = 0; i < n-1; i++) {
        cin >> v[i];
    }
    ans[0]=v[0];
    for (int i = 1; i < n-1; i++) {
        ans[i]=v[i-1]|v[i];
    }
    ans[n-1]=ans[n-2]&v[n-2];
     for (int i = 0; i < n-1; i++) {
        if((ans[i]&ans[i+1])!=v[i]){
            cout<<"-1\n";
         //   cout<<v[i]<<" ";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end());
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