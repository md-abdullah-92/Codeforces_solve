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
    cin >>n>>k;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(n==1){
        cout<<v[0]<<endl;
        return;
    }
    int mnrange=v.back();
    for(int i=0;i<n;i++){
     int q=mnrange-v[i];
     int p=q/k;
     if(p%2==0){
        int kp=v[i]+p*k;
        mp[kp]++;
        mp[kp+k]--;
     }
     else{
        p++;
        int kp=v[i]+p*k;
        mp[kp]++;
        mp[kp+k]--;
     }
    }
    for(int i=-k;i<k;i++){
        mp[i + mnrange] += mp[i + mnrange - 1];
        if(mp[i+mnrange]==n){
            cout << i + mnrange << endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    
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