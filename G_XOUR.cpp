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
    set<int>ans;
    map<int,vector<int>>v;
    map<int,vector<int>>v1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int k=(x/2)/2;
        v[k].push_back(x);
        v1[k].push_back(i);
        ans.insert(k);
    }
    vector<int>ans1(n,0);
    for(auto i:ans){
        sort(v[i].begin(),v[i].end());
        int k=0;
        for(auto j:v[i]){
            int x=v1[i][k]; 
            
           ans1[x]=j;
           k++;
        }
    
    }
    for(auto i:ans1){
        cout<<i<<" ";
    }
     cout<<endl;
    
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