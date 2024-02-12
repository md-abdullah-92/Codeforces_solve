#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "YES\n";
#define no cout << "NO\n";
void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int adj[n+1];
    adj[0]=-1;
    for(int i=1;i<n;i++){
        adj[i]=adj[i-1];
       if(v[i]!=v[i-1]){
        adj[i]=i-1;
       }
    }
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(adj[y-1]<x-1){
            cout<<"-1 -1\n";
        }
        else{
            cout<<adj[y-1]+1<<" "<<y<<endl;
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