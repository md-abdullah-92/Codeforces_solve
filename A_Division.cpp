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
    int rating;
    cin >> rating;
   if(1900<=rating){
    cout<<"Division 1\n";
   }
   else if(1899>=rating&&rating>=1600){
    cout<<"Division 2\n";
   }
   else if(1599>=rating&&rating>=1400){
    cout<<"Division 3\n";
   }
   else{
    cout<<"Division 4\n";
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