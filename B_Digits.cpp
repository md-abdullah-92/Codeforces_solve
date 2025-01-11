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
    int n,d;
    cin >>n>>d;
    map<int,int>mp;
    mp[1]=1;
    if(d==5) mp[5]=1;
    if (n >= 6) {
    mp[9]=1;
   } else {
    int factorial = 1;
    int i = 2;
    while (i <= n) {
        factorial *= i;
        i++;
    }
    if ((factorial * d) % 9 == 0) {
          mp[9]=1;
    }
}
    if (n >= 3 || (n == 2 && d == 7))mp[7]=1;
    if (n >= 3 || d % 3 == 0)  mp[3]=1;
    for(int i=1;i<=9;i+=2){
        if(mp[i]) cout<<i<<" ";
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