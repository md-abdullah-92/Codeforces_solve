#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
template <typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n), v;
    vector<int>mp(n+1,0);
    map<int,int>ans;
    int mx=0;
    for (int i =0; i < n; i++) {
        cin >> v1[i];
        mp[v1[i]]=i;
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
        int k=mp[v2[i]]-i;
        if(k<0) k+=n;
        ans[k]++;
        mx=max(ans[k],mx);
    }
    cout << mx<< endl;
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
