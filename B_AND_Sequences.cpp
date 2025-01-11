#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
const int mod=1e9+7;
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int mn=INT32_MAX;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mn=min(v[i],mn);
    }
    int fact=1;
    for (int i = 1; i < n-1; i++) fact=(fact*i)%mod;

    int cnt=0;
    for(int i=0;i<n;i++) {
        if((v[i]&mn)!=mn){
            cout<<"0\n";
            return;
        }
        if(v[i]==mn)
        cnt++;
    }
    int ans=(cnt*(cnt-1))%mod;
    ans=(ans*fact)%mod;

    cout<<ans<<endl;

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