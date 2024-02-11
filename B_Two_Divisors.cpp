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
    int n,k,z;
    
    cin>>n>>k;
    if(n==1||k==1){
        n=max(n,k);
        cout<<n*n<<endl;
        return;
    }
    z=n*k;
    for(int i=2;i<=sqrt(min(n,k));i++){
        if(k%i==0||n%i==0){
            cout<<i*max(n,k)<<endl;
            return;
        }
    }
    cout<<n*k<<endl;

    
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