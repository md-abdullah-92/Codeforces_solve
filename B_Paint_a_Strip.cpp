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
    if(n<=2){
        cout<<n<<endl;
        return;
    }
    if(n==3){
        cout<<2<<endl;
    }
    else if(n==5){
        cout<<3<<endl;
    }
    else{
        int x=4;
        int ans=2;
        while(n>x){
          x++;
          x*=2;
          ans++;
        }
        cout<<ans<<endl;
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