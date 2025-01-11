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
    int n,k;
    cin >> n>>k;
    set<int>s;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        s.insert(x);
        mp[x]++;
    }
    vector<int>v;
    for(auto x:mp) v.push_back(x.second);
    sort(v.begin(),v.end());
    int ans=0;
    for(int x:v){
        if(k>=x) k-=x;
        else{
         break;
        }
        ans++;
    }
    if(s.size()-ans<1) ans=1;
    else ans=s.size()-ans;
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