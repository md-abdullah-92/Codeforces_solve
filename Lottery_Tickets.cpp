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
const int N=1e6;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    map<int, int> mp;
    int x;
    cin>>x;
    v[0]=x;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
    }
    v[n]=1e6;
    sort(v.begin(),v.end());
    int ans=0;
    if(v[n-1]==x){
        ans=v[n]-v[n-1]+(v[n-1]-v[n-2])/2+1;
        cout<<ans<<endl;
        return;
    }
    else{
        for(int i=0;i<n;i++){
            if(x==v[i]&&i==0){
                ans=(v[i+1]-v[i])/2+v[i];
            }
            else if(x==v[i]){
               ans=(v[i]-v[i-1])/2+(v[i+1]-v[i])/2+1;
            }
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