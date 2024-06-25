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

long long lcm(long long a, long long b) {
    return a * b / __gcd(a, b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;

    cin>>v[0];
    int lcm1 = v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        lcm1 = lcm(lcm1, v[i]);
    }
    int ans = 0;
    vector<int> v1;
    for(int i=0;i<n;i++){
        v1.push_back(lcm1/v[i]);
        ans+=(lcm1/v[i]);
    }
    if(ans>=lcm1){
        cout<<"-1"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        cout<<v1[i]<<" ";
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