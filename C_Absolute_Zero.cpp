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
    cin >> n;
    vector<int> v(n),ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int t=40;
    while(t>=0){
    sort(v.begin(),v.end());
    if((v[0]+v[n-1])%2){
    cout<<"-1\n";
    return;
    }
    k=(v[0]+v[n-1])/2;
    if(k==0) break;
    for(int i=0;i<n;i++){
    v[i]=abs(k-v[i]);
    }
    ans.push_back(k);
    }
    if(k){
    cout<<"-1\n";
    return;
    }
    else{
        cout<<ans.size()<<endl;
        for(int x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }

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