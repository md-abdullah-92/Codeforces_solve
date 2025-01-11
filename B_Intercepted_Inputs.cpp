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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int k=n-2;
    for(int i=0;i<n;i++){
        int x=k/v[i];
        if((k%v[i]==0) &&((x!=v[i]&&mp[x]))){
            cout<<min(v[i],x)<<" "<<max(x,v[i])<<endl;
            return;
        }
        else if((k%v[i]==0) &&(x==v[i]&&mp[x]>1)){
            cout<<min(v[i],x)<<" "<<max(x,v[i])<<endl;
            return;
        }
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