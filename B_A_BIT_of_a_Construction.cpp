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
    if(n==1){
        cout<<m<<endl;
        return;
    }
    int k=1;
    int p=m;
    while(m>1){
        m/=2;
        k*=2;
    }
    cout<<k-1<<" "<<p-k+1<<" ";
    n-=2;
    while(n){
        cout<<0<<" ";
        n--;
    }
     cout<<endl;
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