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
    vector<int> v(n);
    map<int, int> mp;
    int g=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        g=__gcd(v[i],g);
    }
    if(g==0){
        cout<<k<<endl;
        return;
    }
    if(n==1){
        if(v[0]<k){
            cout<<k<<endl;
        }
        else {
            cout<<k-1<<endl;
        }
        return;
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=i*g;
    }
    ans.push_back(1e17);
    int mex=-1;
    for(int i=0;i<n&k>0;i++){
      //  cout<<ans[i]<<" ";
        int l=ans[i];
        int h=ans[i+1];
        
        int range=min(h-l-1,k);

        if(!range) continue;
        k-=range;
        mex=l+range;
    }
    cout<<mex<<endl;

    
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