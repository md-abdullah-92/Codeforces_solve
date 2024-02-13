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
    vector<char>v;
    cin >> n;
    if(n<=28){
        char a='a'+(n-3);
        cout<<"aa"<<a<<endl;
    }
    else if(53>=n){
        int p=n-26;
        char a='a'+(p-2);
        cout<<"a"<<a<<"z\n";
    }
    else{
         int p=n-52;
        char a='a'+(p-1);
        cout<<a<<"zz\n";
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