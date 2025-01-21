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
    vector<int> a(n),diff(n+2,0),op(m+2,0);
    vector<pair<pair<int,int>,int>>v(m+2);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i=1;i<=m;i++){
        int x,y,d;
        cin>>v[i].first.first;
        cin>>v[i].first.second;
        cin>>v[i].second;
    }
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        op[x]++;
        y++;
        op[y]--;
    }
    for(int i=1;i<=m;i++) op[i]+=op[i-1];
    for(int i=1;i<=m;i++){
        int l=v[i].first.first,r=v[i].first.second+1;
        diff[l]+=op[i]*(v[i].second);
        diff[r]-=op[i]*(v[i].second);
    }

    for(int i=0;i<n;i++){
        diff[i+1]+=diff[i];
        a[i]+=diff[i+1];
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;



    
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
 //   cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}