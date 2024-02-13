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
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int p=0,z=n;
    while(v[p]==v[0]) {
        p++;
        z--;
    }
    int q=n-1;
    while(v[q]==v[n-1]) q--;
    if(v[0]!=v[n-1]){
        cout<<min(z,q+1)<<endl;
        return;
    }
    else{
        cout<<max(0ll,(q-p+1))<<endl;
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