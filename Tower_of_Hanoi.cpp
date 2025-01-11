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

void func(int n,int a,int b,int c){
    if(n==0) return;
    func(n-1,a,c,b);
    cout<<a<<" "<<c<<endl;
    func(n-1,b,a,c);
}

void solve()
{
    int n;
    cin >> n;
    cout<<(1<<n)-1<<endl;
    func(n,1,2,3);
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}