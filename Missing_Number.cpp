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
int n;


void solve()
{
    
    cin >> n;
    int a[]={n,1,n+1,0};
    int ans=a[n%4];
    
    for (int i = 0; i < n-1; i++) {
        int x;
        cin >> x;
        ans^=x;
    }
    cout<<ans<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
 //   cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}