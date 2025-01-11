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
    int n,m,k;
    cin >> n>>m>>k;
    vector<int> v(m),v2(k);
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> v2[i];
        mp[v2[i]]++;
    }
    if(k==n){
        for(int i=0;i<m;i++){
            cout<<1;
        }
        cout<<endl;

    }
    else if(k==n-1){
        for(int i=0;i<m;i++){
            cout<<!mp[v[i]];
        }
        cout<<endl;
    }
    else {
        for(int i=0;i<m;i++){
            cout<<0;
        }
        cout<<endl;
    }
    sort(v.begin(),v.end());
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