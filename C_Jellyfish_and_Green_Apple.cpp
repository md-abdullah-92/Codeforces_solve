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
    cin >>n>>m;
    n=n%m;
    if(n==0){
        cout<<0<<endl;
        return;
    }
    int x = n / __gcd(n, m);
    int y = m / __gcd(n, m);
	if(__builtin_popcount(y) > 1){
      cout<<"-1"<<endl;
      return;
    }
    
	int k=1ll*__builtin_popcount(x) * m - n;
    cout<<k<<endl;
    
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