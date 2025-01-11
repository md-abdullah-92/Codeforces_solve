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
    int n,t;
    cin >> n>>t;
    multiset<int>v;
   // map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v.insert(x);
    }
   // sort(v.begin(),v.end());
     for (int i = 0; i < t; i++) {
        int x;
        cin>>x;
        auto y=v.upper_bound(x);

        if(y==v.begin()){
            cout<<"-1\n";
        }
        else {
            y--;
            cout<<*y<<endl;
            v.erase(y);
        }
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}