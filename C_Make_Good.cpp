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
    vector<int>ans;
    int sum=0;
    int xr=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        xr^=v[i];
        sum+=v[i];
    }
    if(sum==2*xr){
    cout<<0<<endl;
    cout<<endl;
    }
    else { 
        sum+=xr;
        cout<<2<<endl;
        cout<<xr<<" "<<sum<<endl;
    }
    
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