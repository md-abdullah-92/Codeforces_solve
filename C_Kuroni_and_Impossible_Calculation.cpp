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
    int n,m;
    cin >> n>>m;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if(m<n){
        cout<<0<<endl;
        return;
    }
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          ans=(ans*abs(v[j]-v[i]))%m;
        }
    }
    cout<<ans<<endl;
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