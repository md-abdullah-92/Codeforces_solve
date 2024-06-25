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
vector<int>adj[200005];

int dfs(int u, int p) {
    int ans = 0;
    for (auto i : adj[u]) {
        if (i != p) {
            ans |= (1 ^ dfs(i, u));
        }
    }
    return ans;
}

void solve()
{
    int n,t;
    cin >> n >> t;
    for (int i = 0; i < n-1; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin>>t;
    int ans = dfs(t, 0);
    cout << (ans ? "Ron" : "Hermione") << endl;
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