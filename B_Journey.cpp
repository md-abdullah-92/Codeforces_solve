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
    int n,a,b,c;
    cin >> n>>a>>b>>c;
    int x=n/(a+b+c);
    int y=n%(a+b+c);
    int p=0;
    if(y==0){
        cout<<x*3<<endl;
        return;
    }
    if(y<=a) p=1;
    else if(y<=(a+b)) p=2;
    else if(y<=(a+b+c)) p=3;
    cout<<x*3+p<<endl;
  
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