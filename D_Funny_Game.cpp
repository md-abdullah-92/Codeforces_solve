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
    vector<int>pos(n);
    iota(pos.begin(),pos.end(),0);
    vector<pair<int,int>>ans;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i=n-1;i;i--){
        vector<int>mp(i,-1);
        for (auto j : pos) {
                if (mp[v[j] % i] != -1) {
                    ans.emplace_back(j, mp[v[j] % i]);
                    pos.erase(find(pos.begin(), pos.end(), j));
                    break;
                }
                mp[v[j] % i] = j;
            }
        }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
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