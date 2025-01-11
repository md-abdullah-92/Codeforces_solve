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
    vector<int> a(n),b(n),c,d;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    c=a,d=b;
    sort(c.begin(),c.end());
     sort(d.begin(),d.end());

    vector<pair<int, int>> ans;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (a[j] > a[j + 1] || b[j] > b[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                    ans.emplace_back(j + 1, j + 2);
                }
            }
        }

        if(c!=a||b!=d){
            cout<<"-1\n";
            return;
        }

        cout << ans.size() << "\n";
        for (const auto& p : ans) {
            cout << p.first << " " << p.second << "\n";
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