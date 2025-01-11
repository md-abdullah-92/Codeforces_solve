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
    int n,l,r,k;
    cin >>n>>l>>r>>k;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        int sum=0;
        int mx=0,mn=INT32_MAX;
      //  int p=-1;
        for(int j=0;j<n;j++){
            if(1<<j&i){
              mx=max(mx,v[j]);
              mn=min(mn,v[j]);
              sum+=v[j];
            //  p++;
            }
        }
        if((sum>=l&&sum<=r)&&(mx-mn)>=k){
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
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}