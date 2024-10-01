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
    cin>>n>>k;
    vector<int> v(n);
    int sum=0;
    int mx=0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum+=v[i];
        mx=max(mx,v[i]);
    }
    int ans=0;
   
    for(int i=1;i<=n;i++){
        if(k==0){
            if(sum%i==0&&sum/i>=mx)
                ans=max(ans,i);
        }
        else{ 
        int x=i-sum%i; 
        if(x==i)
            x=0;
        if(((sum+k)/i>=mx)&&x<=k)
            ans=max(ans,i);
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