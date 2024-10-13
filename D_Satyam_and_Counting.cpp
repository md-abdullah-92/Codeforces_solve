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
    vector<int>v0,v1;
    map<int, int> mp0, mp1;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x;
        cin >> y;
        if(y==0){
            v0.push_back(x);
            mp0[x]++;
        }
        else{
            v1.push_back(x);
            mp1[x]++;
        }
    }
    int ans = 0;
    //sort(v0.begin(),v0.end());
    //sort(v1.begin(),v1.end());
    //cout<<v0.size()<<endl;
    //cout<<v1.size()<<endl;
    for(int i=0;i<v0.size();i++){
        int x = v0[i];
        if(mp1[x]>0){
            ans+=v0.size()-1;   

        }
        if(mp1[x-1]==1&&mp1[x+1]==1){
            ans++;
        }
        
    }
    for(int i=0;i<v1.size();i++){
        int x = v1[i];
        if(mp0[x]>0){
            ans+=v1.size()-1;          
        }
        if(mp0[x-1]&&mp0[x+1]){
            ans++;
        }
        
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