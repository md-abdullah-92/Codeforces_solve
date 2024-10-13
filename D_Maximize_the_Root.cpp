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
int value[2000005];
vector<int>adj[2000005];
int visited[2000005];
void dfs(int x){
    int mini=INT_MAX;
    visited[x]=1;
    int parent=value[x];
    for(auto i:adj[x]){
        if(visited[i]) continue;   
        dfs(i);
        mini=min(mini,value[i]);
    }
    if(x==0) value[x]=mini+parent;
    else
    if(mini>parent&&adj[x].size()) value[x]=(mini+parent)/2;
    else if(mini<=parent&&adj[x].size()) value[x]=mini;
    else value[x]=parent;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < n-1; i++) {
        int x;
        cin>>x;
        x--;
        adj[x].push_back(i+1);
    
    }
    dfs(0);
    cout<<value[0]<<'\n';
    for(int i=0;i<n;i++) {
        adj[i].clear();
        visited[i]=0;
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