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
    int n,a,b;
    cin >> n>>a>>b;
    vector<int> v(n*n);
    map<int, int> mp;
    for (int i = 0; i < n*n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(),v.end());
    vector<int>ans;
    int k=v[0];
    for(int i=0;i<n;i++){
    if(mp[k]){
        ans.push_back(k);
        mp[k]--;
        k+=a;
    }
    else{ 
      no;
      return;
    }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
         k=ans[i]+b;
        for(int j=1;j<n;j++){
        if(mp[k]){
        mp[k]--;
        k+=b;
        }
        else{
        no;
        return;
    }
    }       
    }
    yes;

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