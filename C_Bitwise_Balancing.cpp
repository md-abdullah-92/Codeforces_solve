#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int unsigned long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int x,y,z;
    cin>>x>>y>>z;
    int a=z^y;
    int k=a|x-a&y;
    if(k==z){
        cout<<a<<endl;
    }
    else{
        int a=z^x+y;
         k=a|x-a&y;
        if(k==z){
            cout<<a<<endl;
        }
        else
        cout<<-1<<endl;
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
/*
b c a d
0 0 0 0
0 0 1 1
0 1 0 
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
*/