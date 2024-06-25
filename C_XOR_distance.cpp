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
    int a,b,r;
    cin >> a >> b >> r;
    if(a>b){
        swap(a,b);
    }
    int flag=1;
    int x=0;
    for(int i=60;i>=0;i--){
        int ax=(a>>i)&1;
        int bx=(b>>i)&1;
        if(ax!=bx){
            if(flag){
                flag=0;
            }
            else{
                if(!ax&&(x+(1ll<<i))<=r){
                    x+=(1ll<<i);
                }
            }
        } 
    }
    int ans=abs((a^x)-(b^x));
    cout<<ans<<endl;
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