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
    int n,m;
    cin >> n>>m;
    vector<int> v1(n),v2(n),p;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        if(mp[v1[i]]==0){
            p.push_back(v1[i]);
        }
        mp[v1[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
        if(mp[v2[i]]==0){
            p.push_back(v2[i]);
        }
        mp[v2[i]]++;
    }
    sort(p.begin(), p.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int ans = 0;
        for (auto x : p) {
            int ax = lower_bound(v1.begin(), v1.end(), x) - v1.begin();
            int ay = lower_bound(v2.begin(), v2.end(), x) - v2.begin();
            int k = ax-ay;
            if (k <= m) {
                int buyers = n - ay;
                int earn = x * buyers;
                if (earn > ans) ans = earn;
            }
        }
        cout << ans << "\n";
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