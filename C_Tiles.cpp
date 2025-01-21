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

const int mod=998244353;

int binpow(int a,int n){
    int ans=1%mod;
     while(n>0){
      if(n&1) ans=(ans*a)%mod;
      a=(a*a)%mod;
      n/=2;
     }
     return ans%mod;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int x=binpow(2,m);
    int y=binpow(2,n);
    int ans=(x*y)%mod;
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