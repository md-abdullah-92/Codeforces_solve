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
    vector<int>odd,even;
    if(n<5){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
       if(i%2)
       odd.push_back(i);
       else
       even.push_back(i);
    }
    for(int x:odd) 
    if(x!=5)
    cout<<x<<" ";
    cout<<5<<" ";
    cout<<4<<" ";

    for(int x:even) 
    if(x!=4)
    cout<<x<<" ";
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