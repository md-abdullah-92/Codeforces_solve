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
    map<int, int> mp;
    int k=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        k=max(mp[v[i]],k);
    }
    map<int,int>mp1;
    mp1[0]=mp[0];
    int i=0;
    while(v[i]==0) {
        mp1[0]--;
        i++;
    }
    i=n-1;
    while(v[i]==0) {
        mp1[0]--;
        i--;
    }
    //cout<<mp1[0];
    
    
    if(mp[0]==n){
        cout<<0<<endl;
        return;
    }
    else if(mp[0]==0||mp[0]==1&&(v[0]==0||v[n-1]==0)||(mp[0]==2&&v[0]==0&&v[n-1]==0)||mp[0]==n-1||mp1[0]==0){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
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