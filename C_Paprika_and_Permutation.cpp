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
    vector<int> v(n);
    vector<int>ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){

        if(v[i]>n||mp[v[i]])
        ans.push_back(v[i]);
        else if(v[i]<=n) mp[v[i]]++;
    }
    sort(ans.begin(),ans.end());
    int j=0;
    if(ans.size())
    for(int i=1;i<=n;i++){
        int k=ans[j]-i;
        if(!mp[i]) {
        if(k<=i) {
            cout<<"-1\n";
            return;
        }
        j++;
        }
    }
    cout<<ans.size()<<endl;
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