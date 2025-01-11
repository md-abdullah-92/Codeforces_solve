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
    vector<int> v(n),x;
    map<int, int> mp;
    int sum1=0,sum2=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(i%2==0) sum1+=v[i];
        else sum2+=v[i];
    }
    x=v;
    sort(x.begin(),x.end());
    
    if(sum1/((n+1)/2)==sum2/(n/2)&&sum1%((n+1)/2)==0&&sum2%(n/2)==0){
        yes;
    }
    else no;
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