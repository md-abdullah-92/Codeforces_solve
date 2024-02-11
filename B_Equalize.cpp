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
    vector<int> v;
    set<int>st;
    for (int i = 0; i < n; i++) {
        int k;
        cin>>k;
        st.insert(k);
    }
    for(int k:st) v.push_back(k);
    int ans=1;
    for(int i=0;i<v.size();i++){
        int in = (upper_bound(v.begin(), v.end(), v[i]+n-1)) - v.begin();
        ans = max(ans, in-i);
    }
    cout<<ans<<endl;
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