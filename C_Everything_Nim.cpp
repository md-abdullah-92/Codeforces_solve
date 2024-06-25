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
    vector<int> v;
    vector<int>ans;
    map<int, int> mp;
    int k=0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >>x;
        if(mp[x]==0) v.push_back(x);
        if(x==1) k=1;
        mp[x]++;
    }
    if(k==0){
        cout<<"Alice\n";
        return;
    }
    sort(v.begin(),v.end());
    ans.push_back(v[0]);
    int p=0;
    for(int i=1;i<v.size();i++){
        
        ans.push_back(v[i]-v[i-1]);
        if(ans[i]==1&&p!=1) k++;
        else p=1;
    }
    if(k==0||ans.size()==1){
        cout<<"Alice\n";
    }
    else if(p==0){
        if(k%2==0) cout<<"Bob\n";
        else{
        cout<<"Alice\n";  
        } 
    }
    else {
        if(k%2) cout<<"Bob\n";
        else{
        cout<<"Alice\n";  
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